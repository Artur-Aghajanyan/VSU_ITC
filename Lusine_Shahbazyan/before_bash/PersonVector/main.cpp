#include <iostream>
#include "vec.h"

int main()
{
    myVector<Person> vector;
    Person person1;
    Person person2(26, 170);
    Person person3(person2);
    vector.push_back(person1);
    vector.push_back(person2);
    vector.push_back(person3);
    vector.push_back(Person(20, 165));
    vector.push_back(Person(22, 180));
    vector.push_back(Person(25, 173));
    std::cout << "Print vector" << std::endl;
    vector.print();
    vector.sortBy("age");
    std::cout << "Print vector after sorting by age" << std::endl;
    vector.print();
    vector.sortBy("height");
    std::cout << "Print vector affter sorting by height" << std::endl;
    vector.print();
    std::cout << std::endl;
}
