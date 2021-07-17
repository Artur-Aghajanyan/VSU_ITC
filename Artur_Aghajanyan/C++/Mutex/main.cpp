#include <iostream>
#include <fstream>
#include <chrono>

#define PMFNP   PTHREAD_MUTEX_FAST_NP
#define PMRNP   PTHREAD_MUTEX_RECURSIVE_NP
#define PMENP   PTHREAD_MUTEX_ERRORCHECK_NP

pthread_t t1, t2;
pthread_mutex_t mutex;
pthread_mutexattr_t mattr;
pthread_cond_t cond;

std::string line;
int r1, r2;
int counter = 0;

/* Start Function with thread */
void* countPrinter(void* arr) {
	pthread_mutex_lock(&mutex);

	std::string text = "";
    std::ifstream readFile(*((std::string*)arr+1));
	std::string search = *(std::string*)arr;
		
	if(readFile.is_open() && counter == 0){
		while(getline(readFile, text)) {
			if (text.find(search) != std::string::npos) {
				++counter;
			}	
		}	
		pthread_cond_wait(&cond,&mutex);
	}
	else{
		pthread_cond_signal(&cond);
	}

	std::cout<<"Found With Thread - "<<counter<<" "<<search<<" names in file"<<"\n";
	readFile.close();
	
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
/* End Function with Thread */


/* Start Function without thread */
void countPrinterWithoutThread(std::string* arr){
	std::string text = "";
    std::ifstream readFile;
	readFile.open(arr[1]);
	int counter = 0;
	std::string search = arr[0];

	if(readFile.is_open()){
		while(getline(readFile, text)) {
			size_t nPos = text.find(search, 0);
			while(nPos != std::string::npos) {
				nPos = text.find(search, nPos + 1);
				++counter;
			}	
		}
	}
	std::cout<<"Found without Thread - "<<counter<<" "<<search<<" names in file"<<"\n";
    readFile.close();
}
/* End Function without thread */

int main() {
	std::string* arr = new std::string[2];
	pthread_mutexattr_settype(&mattr, PMRNP); // Creating mutex attribut
	
	std::cout << "Give Me name for Search - ";
	std::cin >> arr[0];
	arr[1] = "data.txt"; // File name

	/* Start Without Thread Function */	
	auto start1 = std::chrono::high_resolution_clock::now();
	
	countPrinterWithoutThread(arr); // Fuction for searching name without thread

	auto stop1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = stop1 - start1;
	/* End Without Thread Function */


	/* Start Thread Functions */
	auto start2 = std::chrono::high_resolution_clock::now();
	
	if(r1 = pthread_create(&t1, NULL, countPrinter,(void*)arr)){
		std::cerr << "Thread 1 returns error" << r1 << std::endl;
	}
	
	if(r2 = pthread_create(&t2, NULL, countPrinter,(void*)arr)){
		std::cerr << "Thread 1 returns error" << r1 << std::endl;
	}
	auto stop2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed2 = stop2 - start2;

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	/* End Thread Functions  */

	// Timer couts
	std::cout<<"Timer without Thread - " << elapsed1.count()<<"\n";
	std::cout<<"Timer with Thread - " << elapsed2.count()<<"\n";
	delete[] arr;	
	return 0;
}
