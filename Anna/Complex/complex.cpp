#include <iostream>
#include "complex.h"

//default constructor, which initialize complex number's real and image parts to 0
Complex::Complex ()
{
	real=0;
	image=0;
}
														
//constructer with parametr to initialize complex number
Complex::Complex(int r, int i)
{
	real=r;
	image=i;
	count++;
}
//copy constructer
Complex::Complex(const Complex &c){
	this->real=c.real;
	this->image=c.image;
}
//overload output  operator for complex number
std::ostream & operator << (std::ostream &out, const Complex &c) 
{ 
    out << "("<<c.real<<")"; 
    out  <<"+"<<"("<< c.image<<")"<< "i"; 
    return out; 
} 
 // overload input operator for real and image parts of complex number
std::istream & operator >> (std::istream &in,  Complex &c) 
{ 
	std::cout << "Input  real "; 
    in >> c.real; 
    std::cout << "Input  image"; 
    in >> c.image; 
    return in; 
} 
//overload addition operator for complex number
Complex operator+ ( Complex const &a, Complex const &b){
	Complex n;
	n.real=a.real+b.real;
	n.image=a.image+b.image;
	return n;
}
//overload subtraction operator for complex number
Complex operator- (Complex const &a,  Complex const &b)
{
	Complex m;
	m.real=a.real-b.real;
	m.image=a.image-b.image;
	return m;
}
//overload multiplication operator for complex numeber
Complex operator* (Complex const &c1, Complex const &c2)
{
	Complex t;
	t.real=c1.real*c2.real-c1.image*c2.image;
	t.image=c1.real*c2.image+c2.real*c1.image;
	return t;
}



