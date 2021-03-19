#include <iostream>
#include "complex.h"

int main() {
	// Creating 2 objects from class Complex
	Complex<int> c1(10,25), c2(5, 6);

	// Test Complex objects for Sum
	std::cout << "**************************\n";
	std::cout << "Give Complex Number For Sum\n\n";
	std::cout << "Object one \n";
	std::cin >> c1;
	std::cout << "\nObject two\n";
	std::cin >> c2;
	std::cout << "\n(a1 + b1i)+(a2 + b2i) = " << c1 + c2 << std::endl << std::endl;
	
	// Test Complex objects for Subtraction
	std::cout << "**************************\n";
	std::cout << "Give Complex Number For Subtraction\n\n";
	std::cout << "Object one \n";
	std::cin >> c1;
	std::cout << "\nObject two\n";
	std::cin >> c2;
	std::cout << "\n(a1 + b1i)-(a2 + b2i) = " << c1 - c2 << std::endl << std::endl;
	
	// Test Complex objects for Multiplocation
    std::cout << "**************************\n";
	std::cout << "Give Complex Number For multiplication\n\n";
	std::cout << "Object one \n";
	std::cin >> c1;
	std::cout << "\nObject two\n";
	std::cin >> c2;
	std::cout << "\n(a1 + b1i)*(a2 + b2i) =  " << c1 * c2 << std::endl << std::endl;
	return 0;
}
