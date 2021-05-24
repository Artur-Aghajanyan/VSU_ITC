#include <iostream>
#include "sort.h"
int main (){
AVector<Person> obj2;
obj2.push_back(Person(5, 140));
obj2.push_back(Person(14, 150));
obj2.push_back(Person(11,155));
obj2.push_back(Person(4,125));

obj2.print();
std::cout<<std::endl;
obj2.Sort("age");
obj2.print();
std::cout<<std::endl;
obj2.Sort("haigth");
obj2.print();
return 0;
}

