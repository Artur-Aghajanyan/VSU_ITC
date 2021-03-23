#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string>

int count = 0;
pthread_mutex_t mutex;

void* func(void* ch) {
    pthread_mutex_lock(&mutex);
    std :: string path = "data.txt";
    std :: ifstream fin;
    fin.open(path);
    if(!fin.is_open()) {
    	std :: cout << "Open file error!" << std :: endl;
	}
	int count = 0;
	while(!fin.eof()) {
		fin.get(*(char*)ch);
		if (*(char*)ch == 'P') {
			++count;
			std :: cout << *(char*)ch << count << std :: endl;
		}
	}
	std :: cout << count << std :: endl;
	fin.close();
	pthread_mutex_unlock(&mutex);
}

int main() {
    char a, b;
    pthread_t t1, t2;
    pthread_attr_t attr;
    int p1 = pthread_attr_init(&attr);
    int state = PTHREAD_CREATE_JOINABLE;
    int l1 = pthread_attr_setdetachstate(&attr,state);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, func, (void*)&a);
    pthread_create(&t2, NULL, func, (void*)&b);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
