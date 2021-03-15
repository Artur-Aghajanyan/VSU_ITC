#include <iostream>
#include "work.h"




int main(){

	Array<std::string> a;
	
	a.push("text1");
	a.push("text2");
	a.push("text3");
	a.push("text4");
	a.push("text5");
	
	a.print();
	std::cout << "\n";
	a.erase(2);
	a.print();
	
	
	return 0;
}
