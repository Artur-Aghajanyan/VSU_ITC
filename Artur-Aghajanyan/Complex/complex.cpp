#include <iostream>
#include "complex.h"


/* 
 * In this file made functionality for class complex without Template
 * Start making functionality for class Complex 
 * Without Template
 * */


// Setter for this->real
void Complex::setReal(int r) {
	this->real = r;
}

// Setter for this->imag
void Complexint::setImag(int i) {
	this->imag = i;
}

// Default constructor
Complex::Complex() {
	this->real = 0;
	this->imag = 0;
}

// Constructor with params
Complex::Complex(int x1, int y1) {
	this->real = x1;
	this->imag = y1;
}

// Copy Constructor
Complex::Complex(const Complex& c) {
	this->real = c.real;
	this->imag = c.imag;
}


// Operator <<
std::ostream& operator << (std::ostream &out, const Complex& c) {
	out << c.real << " + " << c.imag <<"i"<< std::endl;
	return out;
}


// Operator >>
std::istream& operator >> (std::istream& in, Complex& c) {
	std::cout << "Enter Real Part ";
	in >> c.real;
	std::cout << "Enter Imaginory Part ";
	in >> c.imag;
	return in;
}

// Operator -
Complex Complex::operator - (const Complex& c1) const {
	Complex c2;
    c2.real += c1.real;
    c2.imag += c1.imag;
    return c2;
}

// Operator +
Complex Complex::operator + (const Complex& c1) const {
    Complex c2;
    c2.real = real - c1.real;
    c2.imag = imag - c1.imag;
	return c2;
}

// Operator *
Complex Complex::operator * (const Complex& c1) const {
    Complex c2;
    c2.real = real * c1.real - imag * c1.imag;
    c2.imag = (real * c1.imag) + (c1.real * imag);
    return c2;
}

/* 
 * End making functionality for class Complex 
 * Without Template
 * */
