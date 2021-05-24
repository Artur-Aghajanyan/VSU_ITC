#include <iostream>
#include <pthread.h>
#include <string.h>
#include <time.h>

void* function1( void* data1){
char* x = (char*) data1; 
int size = strlen(x);
		std::cout <<size << std::endl;

int count = 0;		
for(int i = 0; i<size; ++i){
	  if (x[i] == 'o' )	
  count = count+1;


    }

 std::cout << count << std::endl;

}



void* function2(void* data2){
	char* y = (char*) data2;

int size = strlen(y);
	std:: cout << size << std::endl;

int count = 0;		
	for(int i = 0; i<size; ++i){
	 if (y[i] == 'a' )	
     count = count+1;


}

 std::cout << count << std::endl;

}
int main(){
clock_t time = clock();
pthread_t thread1,thread2;
pthread_t one, two;
int x, y;

char* text1 = "A thread of execution is a sequence of instructions that can be executed concurrently with other such sequences in multithreading environments, while sharing a same address space.";
char* text2 = "An initialized thread object represents an active thread of execution; Such a thread object is joinable, and has a unique thread id.";


void* t1 = (void*) text1;
void* t2 = (void*) text2;


if(int x = pthread_create(&thread1,NULL,function1, t1)){
		std::cerr << "this is first error" << x;

}
if(int y = pthread_create(&thread1,NULL,function1, t2)){
	    std::cerr << "this is  second error " << y;



}


pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

		 printf("Time taken: %.2fs\n", (double)(clock() - time)/CLOCKS_PER_SEC);

}		
