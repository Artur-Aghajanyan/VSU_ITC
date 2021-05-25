#include <iostream>
#include <string.h>
#include <pthread.h>
void* func (void* str);




int main() {
clock_t c1, c2;
c1=clock();
char* letter1 = new char[26]; // new array
          
               
           for(char ch = 'a'; ch <= 'z'; ++ch)// fills alphabet array with the alphabet
           {
               letter1[ch-'a']=ch;
           } 
char* letter2 = new char[26]; // new array


           for(char ch = 'A'; ch <= 'Z'; ++ch)// fills alphabet array with the alphabet
           {
               letter2[ch-'A']=ch;
           } 


    pthread_t t1, t2;
    pthread_attr_t attr;
    int attr1 = pthread_attr_init(&attr);
    int attr2 = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
   int r1, r2;
   if(r1 = pthread_create (&t1, &attr, func, (void*)letter1))  {
    std::cerr << "Thread 1 returns error"  << r1 << std::endl;
   }
   if(r2 = pthread_create (&t2, &attr, func, (void*)letter2))  {
    std::cerr << "Thread 2 returns error"  << r2 << std::endl;
   }

c2=clock();
float diff((float)c2-(float)c1);
  std::cout<<diff<<std::endl;

   pthread_join(t1, NULL);
   pthread_join(t2, NULL);
    return 0;
}


void* func (void* str){
        char* letter1 = new char[26];
        letter1 = (char*)str;
for(int i=0; i < 26; i++){

std::cout<<letter1[i];
}
}

