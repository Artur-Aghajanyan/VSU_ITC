#include <iostream>
#include <complex.h>


Complex::Complex() {
	this->real = 0;
	this->imag = 0;
};

Complex::Complex(int real1,int imag1) {
	this->real = real1;
	this->imag = imag1;
}

Complex::Complex(const Complex& complex) {
	this->real = complex.real;
	this->imag = complex.imag;
}

std::ostream& operator<<(std::ostream& os,const Complex& complex) {
	os << complex.real << " + " << complex.imag<<"i"<<std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Complex& complex) {
	std::cout<< "enter real number"<<std::endl;	
	is >> complex.real;
	std::cout<< "enter imag number"<<std::endl;
   	is >> complex.imag;
	return is;	
}

Complex Complex::operator + (const Complex& complex) {
	Complex temp;
	temp.real = this->real + complex.real;
	temp.imag = this->imag + complex.imag;
	return temp;
}

Complex Complex::operator - (const Complex& complex) {
	Complex temp;
	temp.real = this->real - complex.real;
	temp.imag = this->imag - complex.imag;
	return temp;
}

// Getters and Setters

int Complex::realGett() {
	return this->real;
}
	
int Complex::imagGett() {
	return this->imag;
}

void Complex::realSet(int r) {
	this->real = r;	
}

void Complex::imagSet(int i) {
	this->image = i;
}

