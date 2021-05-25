#include "Person.h"

Person::Person()
{
	age = 0;
	height = 0;
}

Person::Person(int a)
{
	age = a;
	height = 0;
}

Person::Person(int a, int h)
{
	age = a;
	height = h;
}

Person::~Person()
{

}

void Person::operator=(const Person& p)
{
	this->age = p.age;
	this->height = p.height;
}
