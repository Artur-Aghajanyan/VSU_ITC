#include <iostream>
#include <string>
#include <pthread.h>
#include <fstream>
#include <cstring>

//Create mutex and mutex attribute
pthread_mutex_t mutex;
pthread_mutexattr_t mattr;
pthread_cond_t cond;
pthread_condattr_t cattr;

int done = 0;
std::string searchText; 

//Function with thread
void* print(void* data){
		pthread_mutex_lock(&mutex);
		
		std::string line;
		int count = 0;
		std::ifstream file;
		file.open(*(std::string*)data);
			
		if(file.is_open()) {
			if(done == 0){
			 done = 2;		
			 pthread_cond_wait(&cond,&mutex);
			}	 
			if (done == 2){ 
			pthread_cond_signal(&cond);		
			while(getline(file,line)) {
			  if(line.find(searchText)!=std::string::npos) {
                     ++count;
			  }
			}
			std::cout <<"Found! count = "<< count <<std::endl;
		}
		}	

		file.close();
		pthread_mutex_unlock(&mutex);
		pthread_exit(NULL);
}

//Function without thread
void printNew(std::string data) {
		std::string line;
		int count = 0;
		std::ifstream file;
		file.open(data);
			
		if(file.is_open()){
			while(getline(file,line)){
			  if(line.find(searchText)!=std::string::npos){
                     ++count;
			  }
			}
			std::cout <<"Found! count = "<< count <<std::endl;
		}	
		file.close();
}


int main() {

	std::cout << "Write text for search in data"<<std::endl;
	std::cin >> searchText;
		
	//Create thread attribute 		
	pthread_attr_t attr;
	//Set mutex attribute type	
	pthread_mutexattr_settype(&mattr,PTHREAD_MUTEX_ERRORCHECK_NP);
	int in = pthread_attr_init(&attr);
	int set = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_t t1, t2;
	int r1,r2;
	//Data
	std::string data = "data.txt";
	
	if(set = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED)){
		std::cerr << "SOME ERROR"<<set <<std::endl;
	}	
	//Timer thread
	clock_t timerStart = clock();
	
	if(r1 = pthread_create(&t1,NULL,print, (void*)&data)){
		std::cerr << "SOME ERROR " << r1 <<std::endl;
	}
	if(r2 = pthread_create(&t2,NULL,print, (void*)&data)){	
		std::cerr << "SOME ERROR " << r2 <<std::endl;
	}

	clock_t timerStop = clock();
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	std::cout << "Time search = " << timerStop - timerStart <<std::endl;

	//Timer without tred
	clock_t timeStart = clock();
	printNew(data);
	printNew(data);
	clock_t timeStop = clock();
	std::cout << "Time without thread = "<<timeStop - timeStart<<std::endl;

	return 0;
}




		
