#include <iostream>
#include "complex.h"

int main() {
	/*
	    Criated a Complex variable (number0) with default constructor and inputted a value.
	*/
	Complex number0;
	std :: cout << "Input Re and Im of complex number: ";
	std :: cin >> number0;
	
	/*
		Created two (number1, number2) Complex variables with parametrized constructor.
	*/
	Complex number1(1, 2);
	Complex number2(3, 4);
	
	/*
		Printed number1 and number2.
	*/
	std :: cout << "Output Re and Im of first complex number: " << number1 << std :: endl;
	std :: cout << "Output Re and Im of second complex number: " << number2 << std :: endl;
	
	/*
		Printed the sum, the difference and the product of number1 and number2.
	*/
	std :: cout << "Output the sum of two complex numbers: " << number1 + number2 << std :: endl;
	std :: cout << "Output the difference of two complex numbers: " << number1 - number2 << std :: endl;
	std :: cout << "Output the product of two complex numbers " << number1 * number2 << std :: endl;
	
	/*
		Made a variable (number3) with a copy constructor and coppied number0 in it. 
		Then printed the value of number3.
	*/
	Complex number3 = number0;
	std :: cout << "Output the result of using copy constructor: " << number3 << std :: endl;
	
	/*
        Printing the count of calls of print() function.
    */
	Complex a;
	std :: cout << a.print();
	std :: cout << a.print();
	std :: cout << a.print();
	std :: cout << a.print();
}
