#include <iostream>
#include <cstdlib>
#include <time.h>


void* func(void  *a) 
{
    int n = 10000;
    int* arr = new int[n];
    arr = (int*) a;
    for(int j = 0; j < n; j++) 
    {
        bool isPrime = true;
        if (arr[j] == 0 || arr[j] == 1)
        {
            isPrime = false;
        } else {
            for (int i = 2; i <= arr[j] / 2; ++i) 
            {
                if (arr[j] % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime)
            std::cout << arr[j] << "  ";
    }
}

int main()
{
    clock_t timeTaken = clock();
    pthread_attr_t attr;
    int a1  = pthread_attr_init(&attr);
    int aa2=  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    int size = 10000;
    int* array1 = new int[size];
    int* array2 = new int[size];
    for(int i = 0; i < size; ++i)
    {
        array1[i] = (rand()%200)+1;
    }
    for(int j = 0; j < size; ++j)
    {
        array2[j] = (rand()%200)+1;
    }

    pthread_t t1, t2;
    pthread_create(&t1, &attr, func, (void*)array1);
    pthread_create(&t2, &attr, func, (void*)array2);

    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    std::cout << std::endl;
    std::cout  << "Time taken: "<< ((double) (clock() - timeTaken)) / CLOCKS_PER_SEC;
  

    return 0;
}
