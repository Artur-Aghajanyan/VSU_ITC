#include <iostream>
#include <string>
#include <pthread.h>
#include <chrono>

void* sort1(void* num){
	for(int i = 0; i < 10000; ++i) {
		if(!(*((int*)num+i)%2)) {
			std::cout<<"Number - "<<*((int*)num+i)<<"\t";
		}
	}
}

int main() {
	int* numbers1 = new int[10000];
	int* numbers2 = new int[10000];
	for(int i = 0; i < 10; ++i) {
		numbers1[i] = std::rand()%100;
		numbers2[i] = std::rand()%10;
	}

	auto start1 = std::chrono::high_resolution_clock::now();
	sort1((void*)numbers1);
	sort1((void*)numbers2);
	auto stop1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = stop1 - start1;
	
	pthread_t t1, t2;
	pthread_attr_t attr;

	std::string m1 = "Hello 1";
	std::string m2 = "Hello 2";

	int r1, r2, r3;

	int init = pthread_attr_init(&attr);
	r3 = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	auto start2 = std::chrono::high_resolution_clock::now();
	if(r1 = pthread_create(&t1, NULL, sort1, (void*)numbers1)) {
		std::cerr << "SOME ERROR 1 " << r1 << "\n";
	}
	if(r1 = pthread_create(&t2, NULL, sort1, (void*)numbers2)) {
		std::cerr << "SOME ERROR 1 " << r2 << "\n";
	}

	/*if(!init && !r3 && (r2 = pthread_create(&t2, &attr, message, (void*)&m2))) {
		std::cerr << "Some ERROR  2 " << r2 << "\n";
	}
	*/
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	auto stop2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed2 = stop2 - start2;

	std::cout<<"\nWithout thread spend - "<<elapsed1.count() << " time\n";
	std::cout<<"With Thread spend - "<<elapsed2.count() << " time\n";
	



	return 0;
}
