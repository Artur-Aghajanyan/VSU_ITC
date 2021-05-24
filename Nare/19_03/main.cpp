#include <iostream>
#include "complex.h"
#include "print.h"

int main() {
    /*
     Constructor with parametrs
    */ 
    Complex<int> a(5,2);
    Complex<int> b(3,4);

    /*
     Default constructor
    */ 
    Complex<double> a1;
    Complex<double> b1;
    Complex<int> a2;
    
    /*
     Use of overloaded operator>>
    */ 
    std::cout << "Use of overloaded operator>>" << std::endl;
    std::cout << "(Enter 2 complex numbers)" << std::endl;
    std::cin >> a1;
    std::cin >> b1;
    std::cout << std::endl;

    /*
     Using setters and getters
    */ 
    a2.setReal(5);
    a2.setImage(-3);
    std::cout << "Gave values 5(real), -3(image) using setter funcs. ";
    std::cout << "Get the same values using getter funcs." << std::endl;
    std::cout << a2.getReal() << " " << a2.getImage() << std::endl;
    std::cout << std::endl;

    /*
     Copy constructor and overloaded operator<<
    */
    std::cout << "Use of copy constructor(copies value of b` 3+4i to c) and overloaded operator<<"<<std::endl;
    Complex<int> c = b;
    std::cout << c << std::endl;
    std::cout << std::endl;
    /*
     Use of overloaded operator+
    */ 
    std::cout << "Count (5+2i)+(3+4i)" << std::endl;
    std::cout << a + b << std::endl;
    std::cout << std::endl;

    /*
     Use of overloaded operator-
    */ 
    std::cout << "Count (5+2i)-(3+4i)" << std::endl;
    std::cout << a - b << std::endl;
    std::cout << std::endl;

    /*
     Use of overloaded operator*
    */ 
    std::cout << "Count (5+2i)*(3+4i)" << std::endl;
    std::cout << a * b << std::endl;
    std::cout << std::endl;

    /*
     Use of overloaded operator/
    */ 
    std::cout << "Count entered complex numbers' `";
    std::cout << " (" << a1 << ")/(" << b1 << ") ";
    std::cout << "division (returns int)" << std::endl;
    std::cout << a1 / b1 << std::endl;
    std::cout << std::endl;

    /*
     Use of function with static variable
    */ 
    std::cout << "Called print function with static variable 4 times" << std::endl;
    print();
    print();
    print();
    std::cout << print() << std::endl;

    return 0;
}
