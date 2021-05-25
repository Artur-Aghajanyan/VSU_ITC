#include <iostream>
#include "vector.h"
int main (){
Array obj;
while(true) {
	std::string s;
	std::cin>>s;
	if(s == "end")
	break;
	int x = atoi(s.data());
	obj.push(x);}
//Array obj1(5);
obj.get();
obj[3] = 5;
obj.insert(4, 7);
std::cout<<std::endl;
obj.get();
std::cout<<obj.Size();
std::cout<<std::endl;
std::cout<<obj.empty();
std::cout<<std::endl;
obj.pop_back();
obj.get();
return 0;
}
