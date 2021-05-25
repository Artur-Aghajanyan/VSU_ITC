#include <iostream>
#include <string.h>
#include <pthread.h>

void* func1(void* t1){
	char* x = (char*)t1;
	int size = strlen(x);
	int count = 0;
	for(int i=0; i<size; ++i){
		if(x[i] == 'a'){
			++count;
		}
	}
	std::cout <<"in our data there are  " << count <<"  a" <<std::endl;
}
void* func2(void* t2){
	char* x = (char*)t2;
	int size = strlen(x);
	int count = 0;
	for(int i=0; i<size; ++i){
		if(x[i] == 'b'){
			++count;
		}
	}
    std::cout << "in our data there are  " << count <<"  b" <<std::endl;
}

int main(){
	clock_t tStart = clock();
	pthread_t thread1;
	pthread_t thread2;
	int tr1;
	int tr2;

	char* str1 = "This looks like Dijstra's algorithm. In any case, the time taken to run will depend on N. If it takes more than 3 seconds there isn't any way I can see of speeding it up, as all the calculations that it is doing need to be done.";
			
	char* str2 = "A single argument that may be passed to start_routine. It must be passed by reference as a pointer cast of type void. NULL may be used if no argument is to be passed.";

	void* tmp1 = (void*)str1;
	void* tmp2 = (void*)str2;
	if(tr1 = pthread_create(&thread1 , NULL ,&func1 , tmp1)){
		std::cerr << "Thread erorr \n" <<tr1;
	}
	if(tr2 = pthread_create(&thread2 , NULL , &func2 , tmp2)){
		std::cerr << "Thread erorr \n" <<tr2;
	}
	pthread_join(thread1 , NULL);
	pthread_join(thread2 , NULL);

	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
