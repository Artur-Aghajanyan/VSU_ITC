#include <iostream>
#include "classes.h"
int main() {
	Vector<Person> v;
	v.push_back(Person(15, 155));
	v.push_back(Person(10, 165));
	v.push_back(Person(17, 105));
	v.push_back(Person(18, 115));

	v.print();

	std::string key;
	std::cout << std::endl;

	std::cout << "Enter key for sort: "; 
	std::cin >> key;
	std::cout << std::endl;
	v.sort(key);
	std::cout << std::endl;

	v.print();	
	return 0;
}
