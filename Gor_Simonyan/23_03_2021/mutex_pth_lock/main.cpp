#include <iostream>
#include <pthread.h>
#include <fstream>
#include <regex>
#include <iterator>
#include <time.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int n = 0;

int read(std::string s)
{
	int count = 0;
	std::string myText;
	std::ifstream MyReadFile("bigfile.txt");
	std::regex re(s);
	while(getline(MyReadFile,myText))
	{
		count += std::distance(std::sregex_iterator(myText.begin(),myText.end(),re),std::sregex_iterator());
	}
	return count;
}	

void* func(void* v)
{
	if(n != 0)
	{
		++n;
		pthread_cond_wait(&cond,&mutex);
	}
	else
	{
		pthread_cond_signal(&cond);
	}
	pthread_mutex_lock(&mutex);
	std::string s = *(std::string*)v;
	std::cout<<s<<" - "<<read(s)<<std::endl;
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main()
{
	clock_t tStart = clock();
	std::string s2;
	std::cout<<"Input 1 text for searching - ";
	std::cin>>s2;
	std::string s1;
	std::cout<<"Input 2 text for searching - "
;
	std::cin>>s1;
	pthread_t t1,t2;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&t1,NULL,func,(void*)&s1);
	pthread_create(&t2,NULL,func,(void*)&s2);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&mutex);
	printf("Time: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;

}
