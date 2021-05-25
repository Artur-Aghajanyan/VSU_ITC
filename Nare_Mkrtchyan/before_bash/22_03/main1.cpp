#include <iostream>
#include <pthread.h>
#include <time.h>

void* average1(void *data);
int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int* data1 = new int[100000];
    int* data2 = new int[100000];
    for(int i = 0; i < 100000; i++) {
        data1[i] = (i + 1) * 2;
    }

    for(int i = 0; i < 100000; i++) {
        data2[i] = (i + 1) * 3;
    }
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, average1,(void*)data1 );
    pthread_create(&tid2, NULL, average1,(void*)data2 );

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time used with threads " << cpu_time_used << std::endl;
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}

void* average1(void *data) {
    int* data1 = new int[100000];
    data1 = (int*)data;
    int s = 0;
    for(int i = 0; i < 100000; i++) {
        s = s + data1[i];
    }
    s = s/100000;

    std::cout << "average = " << s << std::endl;
}
