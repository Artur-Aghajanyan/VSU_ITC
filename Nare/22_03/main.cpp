#include <iostream>
#include <time.h>
#include <pthread.h>

int average(int *data);
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
    int a= average(data1);
    int b = average(data2);
    std::cout << "data1's average = " << a << std::endl;
    std::cout << "data2's average = " << b  << std::endl;

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time used without threads " << cpu_time_used << std::endl;
    pthread_exit(NULL);
    return 0;
}

int average(int *data) {
    int* data1 = data;
    int s = 0;
    for(int i = 0; i < 100000; i++) {
        s = s + data1[i];
    }
    return s/100000;
}
