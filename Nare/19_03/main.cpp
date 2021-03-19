#include <iostream>
#include "complex.h"

int print();

int main() {
    /*
     Constructor with parametrs
    */ 
    Complex a(5,2);
    Complex b(3,4);

    /*
     Constructor without parametrs
    */ 
    Complex a1, b1;
    
    /*
     Use of overloaded operator>>
    */ 
    std::cout << "Use of overloaded operator>>" << std::endl << "(Enter 2 complex numbers)" << std::endl;
    std::cin >> a1;
    std::cin >> b1;
    std::cout << std::endl;
    /*
     Copy constructor and overloaded operator<<
    */
    std::cout << "Use of copy constructor(copies value of b` 3+4i to c) and overloaded operator<<"<<std::endl;
    Complex c = b;
    std::cout << c <<std::endl;
    std::cout << std::endl;
    /*
     Use of overloaded operator+
    */ 
    std::cout << "Count (5+2i)+(3+4i)"<<std::endl;
    std::cout << a + b << std::endl;
    std::cout << std::endl;

    /*
     Use of overloaded operator-
    */ 
    std::cout << "Count (5+2i)-(3+4i)"<<std::endl;
    std::cout << a - b << std::endl;
    std::cout << std::endl;

    /*
     Use of overloaded operator*
    */ 
    std::cout << "Count (5+2i)*(3+4i)"<<std::endl;
    std::cout << a * b << std::endl;
    std::cout << std::endl;

    /*
     Use of overloaded operator/
    */ 
    std::cout << "Count entered complex numbers` (" << a1 << ")/(" << b1 << ") division(returns int)" << std::endl;
    std::cout << a1 / b1 << std::endl;
    std::cout << std::endl;

    /*
     Use of function with static variable
    */ 
    std::cout << "Called print function with static variable 4 times"<<std::endl;
    print();
    print();
    print();
    std::cout<<print()<<std::endl;
return 0;
}

/*
  Function with static variable 
*/
 int print() {
     static int count = 0;
     ++count;
     return count;
 }

