#include <iostream>
#include <fstream>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
char filename1[10] = "file.txt";
char filename2[10] = "file1.txt";

void *WordNum(void *filename)
{
	char* str;
	str = (char*) filename;
	std::ifstream fin(str );
    pthread_mutex_lock(&mutex); 

	int word=1;
	char ch;
	fin.seekg(0,std::ios::beg); 
	while(fin)
 		{
 			fin.get(ch);
			if(ch==' '||ch=='\n') word++; 
		}
	std::cout<<"\nWords="<<word<<"\n";
	fin.close(); 
	pthread_mutex_unlock(&mutex);

return NULL;
}


int main(){
	pthread_t thread1; 
	pthread_t thread2;
	pthread_attr_t attr;
    clock_t start = clock();
 	int attr1 = pthread_attr_init(&attr);
    int attr2 = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

    if(pthread_create(&thread1, &attr, WordNum, (void*)&filename1))  
    {
    	std::cout<<"error creating thread.";  
    }

    if(pthread_create(&thread2, &attr, WordNum, (void*)&filename2))
    {
        std::cout<<"error creating thread.";
    }
   
	clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    
    printf("Time measured: %.3f seconds.\n", elapsed);
 pthread_join(thread1, NULL);
 pthread_join(thread2, NULL);
//  printf("Time measured: %ld seconds.\n", elapsed);
 
    return 0;
}

