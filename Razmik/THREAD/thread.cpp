#include <iostream>
#include <pthread.h>
#include <time.h>
#include <fstream>

pthread_mutex_t myMutex;
pthread_mutexattr_t mutexAttr;

 void* function1(void* first ){
  


//pthread_mutexattr_settype(&mutexAttr,PTHREAD_MUTEX_FAST_NP);
pthread_mutex_init(&myMutex, &mutexAttr);


  
          std::string line1 = "";
          std::string line_first = "";
 			std :: string tmp = *(std :: string*)first;


          pthread_ mutex_lock(&myMutex); 
          std::ifstream object1("file.txt");
          while( getline(object1,line_first)){
				size_t found = line_first.find(tmp);
    if (found != std::string::npos)
        std :: cout << tmp << std :: endl;
  
    // Find next occurrence of 'g'
    found = line_first.find(tmp, found+1);
    if (found != std ::string::npos)
        std :: cout << tmp << std :: endl;
                  
          }
 
          object1.close();

// std::cout << tmp << std::endl;
pthread_mutex_unlock(&myMutex);
pthread_mutex_destroy(&myMutex);
pthread_exit(NULL);




     }		  

 
int main() {

clock_t tStart1 = clock();
  std :: string tmp = "Margo"; 
  function1((void*)&tmp);
  std :: string tmp1 = "Henry";
  function1((void*)&tmp1);

printf("Time taken: %.2fs\n", (double)(clock() - tStart1)/CLOCKS_PER_SEC);


clock_t tStart2 = clock();
  pthread_t id1,id2;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  tmp = "Margo"; 
  int x= pthread_create( &id1, &attr, function1,(void*)&tmp);
  tmp1 = "Henry";
  int y = pthread_create( &id2,&attr, function1,(void*)&tmp1);
 
 
  pthread_join(id1,NULL);
  pthread_join(id2,NULL);
  
  
 
printf("Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);
pthread_exit(NULL);
 return 0;
 }
