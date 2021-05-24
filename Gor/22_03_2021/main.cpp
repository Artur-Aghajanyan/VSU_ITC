#include <iostream>
#include <pthread.h>
#include <stdlib.h>

void* func(void* v)
{
	srand (time(NULL));
	char arr1[26];
        int q = 0;
        for(int i = 'a';i < 'z'; ++i)
        {
                arr1[q] = i;
                ++q;
        }
        int r = rand() % 1000000 + 900000;
        char arr2[r];
        for(int i = 0; i < r; ++i)
        {
                int r2 = rand() % 25;
                arr2[i] = arr1[r2];
        }

	char s = *(char*)v;
	int count = 0;
	for(int i = 0;i < r; ++i)
	{
		if(s == arr2[i])
		{
			std::cout<<arr2[i]<<std::endl;
			++count;	
		}
	}
	std::cout<<count<<std::endl;	
}

int main()
{
	char m1 = 'a';
	char m2 = 'j';
	pthread_t t1,t2;
	pthread_attr_t attr;
	int i = pthread_attr_init(&attr);
	int state = PTHREAD_CREATE_JOINABLE;
	int s = pthread_attr_setdetachstate(&attr,state);
	int r1,r2;
	if(r1 = pthread_create(&t1,&attr,func,(void*)&m1))
	{
		std::cerr<<"Thread 1 returns error"<<r1<<std::endl;
	}
	if(r2 = pthread_create(&t2,&attr,func,(void*)&m2))
        {
                std::cerr<<"Thread 2 returns error"<<r1<<std::endl;
        }
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_exit(NULL);
}
