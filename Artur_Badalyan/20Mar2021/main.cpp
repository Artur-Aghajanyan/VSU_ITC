#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>


void* print(void* array){
int counter = 0;
	for(int i = 1;i < 1000;++i)	{
		if(*(int*)array <= *((int*)array+i))
				++counter;
					
	}
		std::cout <<"Num count = " << counter <<"\n";
}

int main() {

	
	int* array = new int[1000];
	int* array1 = new int[1000];	
	for (int i = 1;i < 1000;++i){
		array1[i] = std::rand() % 100;
		array[i] = std::rand() % 1000 + 1;

	}


	int x = 0;
	int num;
	std::cout << "Write num for search in array"<<std::endl;
	std::cin >> num;
	array[0] = num;
	array1[0] = num;
	clock_t startT = clock();
	print((void*)array);
	print((void*)array1);

	clock_t stopT = clock();



	/*   
	pthread_attr_t attr;	
	
	int in = pthread_attr_init(&attr);
	int set = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	*/
	pthread_t t1, t2;
	std::string m1 = "Thread_1";
	std::string m2 = "Thread_2";
	int r1,r2;

	/*
	if(set = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED)){
		std::cerr << "SOME ERROR"<<set <<std::endl;
	}*/
	
	clock_t threadS = clock();

	if(r1 = pthread_create(&t1,NULL,print,(void*)array)){			
		std::cerr << "SOME ERROR " << r1 <<std::endl;
	}

	if(r2 = pthread_create(&t2,NULL,print,(void*)array1)){
		std::cerr << "SOME ERROR " << r2 <<std::endl;
	}

	clock_t threadE = clock();
	
    
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	std::cout <<"\n" <<"Num count = "<< x << "TIME = " << stopT - startT <<std::endl;
	std::cout <<"Thread time = "<< threadE - threadS  <<std::endl;


	return 0;
}




		
