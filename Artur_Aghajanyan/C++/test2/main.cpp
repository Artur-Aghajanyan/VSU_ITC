#include <iostream>
#include "list.h"
int main(){
	List<std::string> list;
	list.push("String 0");
	list.push("String 1");
	list.push("String 2");
	list.push("String 3");
	list.push("String 4");
	list.push("String 5");
	list.push("String 6");
	list.print();
	std::cout<<"\n*** After POP ***\n";
	list.pop();
	list.print();
	std::cout<<"\n*** After Erase ***\n";
	list.erase(3);
	list.print();
	std::cout<<"\n*** After insert ***\n";
	list.insert(3, "String 3");
	list.print();
	std::cout<<"\n*** After Operator ***\n";
	int k;
	std::cout<<"Give Index For Operator: ";
	std::cin>>k;
	std::cout<<list[k]<<std::endl;
	return 0;
}
