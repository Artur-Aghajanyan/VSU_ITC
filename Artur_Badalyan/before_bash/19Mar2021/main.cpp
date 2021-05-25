#include <iostream>
#include "complex.h"
#include <fstream>


int main() {

		
	std::cout << "Write number for sum,subtraction,multiplication";
	Complex<int> a;
	Complex<int> b;
	std::cin >> a;
	std::cin >> b;

	std::cout << "\n" << "-----sum-----" <<std::endl;
    std::cout << "(a + ai) + (b + bi) = " << a + b << "\n";

	std::cout << "\n" << "-----subtraction-----" <<std::endl;
    std::cout << "(a + ai) - (b + bi) = " << a - b << "\n";

	std::cout << "\n" << "-----multiplication-----" <<std::endl;
    std::cout << "(a + ai) * (b + bi) = " << a * b << "\n";


	return 0;
}
