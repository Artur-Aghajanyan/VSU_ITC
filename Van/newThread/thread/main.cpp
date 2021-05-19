#include <iostream>
#include <fstream>
#include <time.h>
#include <pthread.h>

void* func1(void* x1){
	
	std::ifstream obj1("file1.txt");
	std::string str1 = "";
	std::string tmp1;
   while(getline(obj1 , tmp1)){
   	str1 = str1 + tmp1 + "\n";
   obj1.close();
   }
   int count = 0;
   int f = str1.size();
   for(int i=0; i<f; ++i){
   	if(str1[i] = 'a'){
		++count;
	}
   }
   std::cout <<"there are  " << count << "  a" <<std::endl;
}


void* func2(void* x2){
	
   std::ifstream obj2("file2.txt");
   std::string str2 = "";
   std::string tmp2;
   while(getline(obj2 , tmp2)){
   		str2 = str2 + tmp2 + "\n";
   }
   obj2.close();

   int count = 0;
   int h = str2.size();
   for(int i=0; i<h; ++i){
   	if(str2[i] = ' '){
		++count;
	}
   }
   std::cout <<"there are  " << count << "  spase " <<std::endl;
}


int main(){
	clock_t tStart = clock();
		func1(NULL);
		func2(NULL);
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
/// function with threads
	clock_t tStart2 = clock(); 
    pthread_t id1,id2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 
    int x= pthread_create( &id1, &attr, func1,NULL);
    int y = pthread_create( &id2,&attr, func2,NULL);
 
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
	
	printf("Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);

return 0;   
}
