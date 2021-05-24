#include <iostream>
#include "sort.h"
using namespace std;



int main() {

	customVector<Person> p1;
   	p1.push_back(Person (8,15));	
	p1.push_back(Person (78,45));	
	p1.push_back(Person (16,5));	
	p1.push_back(Person (45,78));	
	p1.push_back(Person (89,178));	
	p1.push_back(Person (50,12));	
	p1.push_back(Person (42,210));

	p1.print();
	
	p1.sortBy("age");	
	
	p1.print();
};
