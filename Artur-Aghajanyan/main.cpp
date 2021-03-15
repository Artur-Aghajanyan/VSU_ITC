#include <iostream>
#include <string>
#include "array.h"

int main(){
	ITC::Array<std::string> arr;

	std::cout << "Object for String\n";
	arr.push("String 1");
	arr.push("String 2");
	arr.push("String 3");
	arr.push("String 4");
	arr.push("String 5");
	arr.push("String 6");
	arr.print();
	std::cout << "\nPOP For String \n";
	arr.pop();
	arr.print();
	std::cout << "\nErasc For String\n";
	arr.erasc(2);
	arr.print();
	
	ITC::Array<int> arr1;

	std::cout << "\nObject for Int\n";
	arr1.push(1);
	arr1.push(2);
	arr1.push(3);
	arr1.push(4);
	arr1.push(5);
	arr1.push(6);
	arr1.print();
	std::cout << "\nPOP For Int \n";
	arr1.pop();
	arr1.print();
	std::cout << "\nErasc For Int\n";
	arr1.erasc(2);
	arr1.print();
	
	return 0;
}
