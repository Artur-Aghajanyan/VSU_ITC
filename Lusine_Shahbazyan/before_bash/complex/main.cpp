#include <iostream>

#include "comp.cpp"
#include "function.h"

int main() {
    /* Call default constructor and print complex number */
    Complex<int> objDef;
    std::cout << "Printing an object created by default constructor  :  " << objDef << std::endl;
    
    /* with set function give value to objDef */
    objDef.setReal(6); 
    objDef.setImage(2);
    std::cout << "Print objDef after calling setter functions : ";
    std::cout << objDef << std::endl;

    /* With get function get value of objDef */
    std::cout << "Printing  values by calling getter functions " << std::endl;
    std::cout << "objDef.real = " << objDef.getReal() << std::endl;
    std::cout << "objDef.image = " << objDef.getImage() << std::endl;

    /* Call parametrize constructor and print complex number */
    Complex<int> objPar(5, 9);
    std::cout << "Printing an object created by parametrize constructor  :  " << objPar << std::endl;

    /* Input complex number by using overloaded operator  >>  */
    Complex<int> number1;
    std::cin >> number1;
    std::cout << "Complex number1 is  : " << number1 << std::endl;

    /* Call copy constructor and print duplicated complex number */
    Complex<int> number2 = objPar;
    std::cout << "Complex number2 is created by copy constructor : " << number2 << std::endl;

    /* Calculate the sum of two complex numbers by overloaded operator + */
    std::cout << "Sum of number1 and number2 is : " << number1 + number2 << std::endl;

    /* Calculate the difference two complex numbers by overloaded oerator -  */
    std::cout << "Difference of number1 and number2 is : " << number1 - number2 << std::endl;

    /* Multiply two complex numbers by overloaded operator *  */
    std::cout << "Multiply number1 and number2  :  " << number1 * number2 << std::endl;
    /* Call print function and print count of calls */ 
    print();
    print();
    print();
    print();
    print();
    std::cout << "Count of calls is  " << print() << std::endl;

}





