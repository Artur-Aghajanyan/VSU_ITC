#include <iostream>
#include <time.h>
#include <fstream>
#include <pthread.h>
#include <string>

/* Global variables */
pthread_mutex_t myMutex1;
pthread_mutex_t myMutex2;
pthread_cond_t cond;

/* Function for searching word in first file */
void* funcSearch1(void* str)
{
    pthread_mutexattr_t attrMut1;
    pthread_mutexattr_settype(&attrMut1, PTHREAD_MUTEX_FAST_NP);
    pthread_mutex_init(&myMutex1, &attrMut1);
    pthread_mutex_lock(&myMutex1);
    std::string myString = *(std::string*) str;
    std::ifstream myFile ("cpp.txt");
    if( myFile.is_open() )
    {
        int count = 0;
        std::string candidate;
        while(myFile >> candidate)
        {
            if(myString == candidate) ++count;
        }
        std::cout << "The word " << myString << " has been found " << count << " times.";
       // pthread_cond_wait(&cond, &myMutex1);
    } else {
        std::cout << "Error! File not found!\n";
    }
    myFile.close();
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&myMutex1);
    pthread_mutex_destroy(&myMutex1);
    pthread_cond_signal(&cond);
    //pthread_cond_broadcast(&cond);  // Wake up all waiting threads
    pthread_cond_destroy(&cond);
    pthread_exit(NULL);

}

/* Function for searching word in second file */
void* funcSearch2(void* str)
{
    pthread_mutexattr_t attrMut2;
    pthread_mutexattr_settype(&attrMut2, PTHREAD_MUTEX_FAST_NP);
    pthread_mutex_init(&myMutex2, &attrMut2);
    pthread_mutex_lock(&myMutex2);
    std::string myString = *(std::string*) str;
    std::ifstream myFile ("cpp1.txt");
    if( myFile.is_open() )
    {
        int count = 0;
        std::string candidate;
        while(myFile >> candidate)
        {
            if(myString == candidate) ++count;
        }
        std::cout << "The word " << myString << " has been found " << count << " times.\n";
    } else {
        std::cout << "Error! File not found!\n";
    }
     myFile.close();

    pthread_mutex_unlock(&myMutex2);
    pthread_mutex_destroy(&myMutex2);
    pthread_exit(NULL);
}

/* searching without threads */
void noThread(std::string str)
{
    std::string myString = str;
    std::ifstream myFile ("cpp1.txt");
    if( myFile.is_open() )
    {
        int count = 0;
        std::string candidate;
        while(myFile >> candidate)
        {
            if(myString == candidate) ++count;
        }
        std::cout << "The word " << myString << " has been found " << count << " times.\n";
    } else {
        std::cout << "Error! File not found!\n";
    }
    myFile.close();

    std::ifstream myFile1 ("cpp.txt");
    if( myFile1.is_open() )
    {
        int count = 0;
        std::string candidate;
        while(myFile1 >> candidate)
        {
            if(myString == candidate) ++count;
        }
        std::cout << "The word " << myString << " has been found " << count << " times.\n";
    } else {
        std::cout << "Error! File not found!\n";
    }
    myFile1.close();
}

int main()
{
    /* Set timer, creating threads and attributs */
    clock_t timeTaken = clock();
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    std::string  mySearch = "C++";
    pthread_t thread1, thread2;
    pthread_create(&thread1, &attr, funcSearch1, (void*) & mySearch);
    pthread_create(&thread2, &attr, funcSearch2, (void*) & mySearch);
    //pthread_attr_getdetachstate(&attr, PTHREAD_CREATE_JOINABLE);      Reminder to watch the errors
    pthread_attr_destroy(& attr);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    std::cout << std::endl;
    /* Print time when is using thread */
    std::cout << "Time taken with threads: "<< ((double) (clock() - timeTaken)) / CLOCKS_PER_SEC;
    std::cout << std::endl << std::endl;

    clock_t timeTaken1 = clock();
    noThread(mySearch);
    /* Print time without using thread */
    std::cout << "Time taken: "<< ((double) (clock() - timeTaken1)) / CLOCKS_PER_SEC;
    std::cout << std::endl << std::endl;
    return 0;
}         
