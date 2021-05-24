#include <iostream>
#include "complex.h"

using namespace std;

Complex::Complex() //default constructor
{
	real = 0;
	imag = 0;
}

Complex::Complex(int r,int i) //arguments constructor
{
	real = r;
	imag = i;
}

Complex::Complex(const Complex& c) //copy constructor
{
	real = c.real;
	imag = c.imag;
}

Complex Complex::operator+(const Complex& a) //overloading op. +
{
	Complex n;
	n.real = this->real + a.real;
	n.imag = this->imag + a.imag;
	return n;
}

Complex Complex::operator-(const Complex& b) //overloading op. -
{
        Complex n;
        n.real = this->real - b.real;
        n.imag = this->imag - b.imag;
        return n;
}

Complex Complex::operator*(const Complex& c) //overloading op. *
{
	Complex n;
	n.real = this->real * c.real - this->imag * c.imag;
	n.imag = this->real * c.imag + c.real * this->imag;
	return n;
}

std::istream& operator>>(std::istream& in, Complex& i) //overload op. >> (cin>>)
{
	char oper;
	char u;
	in >> i.real >> oper >> i.imag >> u;
	return in;
}

std::ostream& operator<<(std::ostream &out, Complex &o) //overload op. << (cout<<)
{
	out << o.real << "+" << o.imag << "i";
	return out;
}
