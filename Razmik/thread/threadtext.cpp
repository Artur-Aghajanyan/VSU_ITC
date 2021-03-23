#include <iostream>
#include <fstream>
#include <time.h>
#include <pthread.h>



void* function1(void* first ){


		std::string line1 = "";
        std::string line_first = "";
		
		std::ifstream object1("a.txt");
		while( getline(object1,line_first)){
				line1 = line1 + line_first + "\n";
		}
         

        object1.close();		


int count = 0;
int x = line1.size();
for(int i = 0;i< x; ++i){

		if(line1[i] = 'a')
				count = count + 1;
}

		std:: cout << count << std::endl;

}

void* function2(void* second){

        std::string line2 = "";
	    std::string line_second = "";

        std::ifstream object2("b.txt");
		while( getline(object2,line_second)){
                  line2 = line2 + line_second + "\n";
        }
       
 
        object2.close();

}


int main(){
clock_t tStart1 = clock();
function1(NULL);
function2(NULL);


 
printf("Time taken: %.2fs\n", (double)(clock() - tStart1)/CLOCKS_PER_SEC);
   


clock_t tStart2 = clock();

pthread_t id1,id2;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);



int x= pthread_create( &id1, &attr, function1,NULL);
int y = pthread_create( &id2,&attr, function2,NULL);


pthread_join(id1,NULL);
pthread_join(id2,NULL);
printf("Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);
return 0;
}
		
