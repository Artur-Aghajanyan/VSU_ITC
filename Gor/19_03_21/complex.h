#include <iostream>

class Complex
{
	int real;
	int imag;
	public:
		Complex();
		Complex(int r,int i);
		Complex(const Complex& c);
		Complex operator+(const Complex& a);
		Complex operator-(const Complex& b);
		Complex operator*(const Complex& c);
		friend std::ostream& operator<<(std::ostream &out, Complex &o);
		friend std::istream& operator>>(std::istream& in, Complex& i);

};
