#include <iostream>
#include <fstream>
#include <time.h>

char filename1[10] = "file.txt";
char filename2[10] = "file1.txt";

void WordNum(char *filename)
{
	char* str;
	str = (char*) filename;
	std::ifstream fin(str );
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

}


int main(){
	//pthread_t thread1; 
	//pthread_t thread2;
	//pthread_attr_t attr;
    clock_t start = clock();
 	//int attr1 = pthread_attr_init(&attr);
    //int attr2 = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

WordNum(filename1);
WordNum(filename2);

   
	clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    
    printf("Time measured: %.3f seconds.\n", elapsed);
 
    return 0;
}

