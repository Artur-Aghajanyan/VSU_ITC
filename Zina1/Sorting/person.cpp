#include "person.h"

Person :: Person() {
	this -> age = 0;
	this -> height = 0;
}

Person :: Person (int a) {
	this -> age = a;
	this -> height = 0;
}

Person :: Person (int a, int h) {
	this -> age = a;
	this -> height = h;
}

void Person :: operator = (const Person& person) {
	this -> age = person.age;
	this -> height = person.height;
}
