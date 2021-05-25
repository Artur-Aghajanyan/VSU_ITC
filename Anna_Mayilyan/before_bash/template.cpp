#include <iostream>
#include "t.h"
int main(){
        Array<int> num;

        while(true)
	{
                std::string s;
                std::cin>>s;
                if(s=="end")
                        break;
		else 
		{ 
		int x=atoi(s.data());
                num.push(x);}
        }
Array<std::string>  string;

	while(true)
	{ 
		std::string str;
		std::cin>>str;
		if(str=="end")
			break;
		else
			string.push(str);
	}
        num.get();
	string.get();
num.pop();
	std::cout<<std::endl;
     num.get();
string.pop();
	string.get();
return 0;
}
