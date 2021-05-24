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
	
=======
#include <cstring>

class Person{

	public:
	Person(){
		this->age = 10;	
	}
	Person(const Person &p1){
		
		//memcpy(this->data, p1.data, 80);
		this->age = p1.age;
		this->data = new double[10];
		for(int i = 0; i< 10; i++){
			this->data[i] = p1.data[i];
		}
	};
	int age = 10;
	double* data = new double[10];
};


int main(){
	Person p1;
	p1.age = 15;
	
	std::cout << "--------\nBefor copy\n---------\n";
	for(int i = 0; i < 10; i++){
		p1.data[i] = 100+i;
		std::cout << p1.data[i] << " - p1"<<i<<std::endl;
	}
	std::cout << p1.age << " - p1.age\n";
	
	Person p2 = p1;

	p1.age = 20;
	std::cout << "---------\nAfter copy\n---------\n";

	for(int i = 0; i < 10; i++){
		p1.data[i] = 200+i;
		std::cout << p1.data[i] << " - p1"<<i<<std::endl;
	}
	std::cout << p1.age << " - p1.age\n\n";
	for(int i = 0; i < 10; i++){
		std::cout << p2.data[i] << " - p2"<<i<<std::endl;
	}
	std::cout << p2.age << " - p2.age\n";
	return 0;
}
