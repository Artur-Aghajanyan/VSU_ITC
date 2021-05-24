#include <iostream>
#include "class.h"

int main() {
    MyVector<Person> P;
    P.push_back(Person(27,185));
    P.push_back(Person(16,191));
    P.push_back(Person(21,188));
    P.push_back(Person(25,182));
    P.push_back(Person(26,175));
    P.push_back(Person(24,178));


    std::string s;
    std::cout << "Enter parameter to search" << std::endl;
    std::cin >> s;
    P.my_sort(s);
    P.print();
    return 0;
}
