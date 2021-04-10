#include "person.cpp"
#include "vector.h"

int main() {
	Vector<Person> v;
	v.push_back(Person(4, 12));
	v.push_back(Person(2, 7));
	v.push_back(Person(37, 162));
	v.push_back(Person(68, 159));
	v.Sort("height");
	v.print();
  v.Sort("age");
  v.print();
}
