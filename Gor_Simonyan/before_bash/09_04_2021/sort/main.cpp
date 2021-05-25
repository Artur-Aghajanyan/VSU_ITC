#include "Vector.h"

int main()
{
	myVector<Person> p1;

	p1.push_back(Person(3,20));
	p1.push_back(Person(5,15));
  	p1.push_back(Person(23,20));
    	p1.push_back(Person(86,65));	
    	p1.push_back(Person(6,35));

	p1.print();

	p1.Sort("age");
	cout<<"___Age___"<<endl;
	p1.print();

	p1.Sort("height");
	cout<<"___Height___"<<endl;
	p1.print();

	return 0;
}
