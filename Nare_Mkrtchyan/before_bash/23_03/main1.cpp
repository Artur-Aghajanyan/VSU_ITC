#include <iostream>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <pthread.h>

const int arrSize = 35450;
int size = 35425;

pthread_mutex_t mutex; //without mutex worked not correctly
pthread_cond_t cv;
int done = 1;

std::string col1[arrSize];
std::string col2[arrSize];
std::string col3[arrSize];
std::string col4[arrSize];
std::string GNAT;

void* myOpenFile(void* fileName);
int nat(std::string* col4);

int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    std::cin >> GNAT;
    int num = 0;
    std::string file1 = "ATP";
    std::string file2 = "WTA";

    std::string file3 = "ATP1";
    std::string file4 = "WTA1";

    pthread_t tid1, tid2, tid3, tid4;
    pthread_attr_t my_attr;
    
    pthread_attr_init(&my_attr);
    pthread_attr_setdetachstate(&my_attr,PTHREAD_CREATE_JOINABLE);
 //   pthread_attr_setdetachstate(&my_attr,PTHREAD_CREATE_DETACHED); //tried to use join with detached to check if it is not working

    pthread_create(&tid1, &my_attr, myOpenFile,(void*)&file1 );
    sleep(1);
    pthread_create(&tid2, &my_attr, myOpenFile,(void*)&file2 );
    pthread_create(&tid3, NULL, myOpenFile,(void*)&file3 );
    pthread_create(&tid4, NULL, myOpenFile,(void*)&file4 );

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);

    pthread_attr_destroy(&my_attr);
    pthread_mutex_destroy(&mutex);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time used with threads " << cpu_time_used << std::endl;
    return 0;
}

void* myOpenFile(void* fileName) {
    pthread_mutex_lock(&mutex);
    std::string* fname = (std::string*)fileName;
    std::string fn = *fname;   
    int num = 0; 
    if(done == 1) {
        done = 2;
        std::cout << "wait" << std::endl;
        pthread_cond_wait(&cv, &mutex);
    }
    else {
        std::cout << "signal" <<std::endl;
        pthread_cond_signal(&cv);
    }
    std::cout << "end`_waiting" << std::endl;
    std::fstream my_file;
    my_file.open(fn.c_str());
    if(my_file.fail()) {
        std::cout << "No such file" << std::endl;
       exit(0);
    }
    while(!my_file.eof()){
        my_file >> col1[num];
        my_file >> col2[num];
        my_file >> col3[num];
        my_file >> col4[num];
        
        ++num;
    }
    

    std::cout << nat(col4) << std::endl;
    my_file.close();
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
    return NULL;
}

int nat(std::string* col4) {
    int count = 0;
    for(int i = 0; i < size; ++i) {
        if(col4[i] == GNAT) {
            ++count;
        }
    }
    return count;
}

