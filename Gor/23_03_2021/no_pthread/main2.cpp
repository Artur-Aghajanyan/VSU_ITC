#include <iostream>
#include <fstream>
#include <regex>
#include <iterator>
#include <time.h>

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
	std::cout<<s2<<" - "<<read(s2)<<std::endl;
	std::cout<<s1<<" - "<<read(s1)<<std::endl;
	printf("Time: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;

}
