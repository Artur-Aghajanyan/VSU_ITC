#include <istream>
#include <ostream>
#include "complex.h"

/*
    Default constructor
*/
Complex :: Complex() {
	real = 0;
	image = 0;
}

/*
    Parametrized constructor
*/
Complex :: Complex(int real, int image) {
	this -> real = real;
	this -> image = image;
}

/*
    Copy constructor
*/
Complex :: Complex(const Complex& number2) {
	this -> real = number2.real;
	this -> image = number2.image;
}

/*
    Overloaded output operator - <<
*/
std :: ostream& operator << (std :: ostream& output, const Complex& number) {
	output << "Re = " << number.real << " Im = " << number.image << ' ';
	return output;
}

/*
    Overloaded input operator - >>
*/
std :: istream& operator >> (std :: istream& input, Complex& number) {
	input >> number.real >> number.image;
	return input;
}

/*
    Overloaded addition (+) operator
*/
Complex Complex :: operator + (const Complex& number) {
	Complex sum;
	sum.real = real + number.real;
	sum.image = image + number.image;
	return sum;
}

/*
    Overloaded subtraction (-) operator
*/
Complex Complex :: operator - (const Complex& number) {
	Complex difference;
	difference.real = real - number.real;
	difference.image = image - number.image;
	return difference;
}

/*
    Overloaded multipliction (*) operator
*/
Complex Complex :: operator * (const Complex& number) {
	Complex product;
	product.real = real * number.real - image * number.image;
	product.image = real * number.image + number.real * image;
	return product;
}

/*
    Set function for real part of complex number
*/
void Complex :: setReal(int r) {
    real = r;
}

/*
    Set function for imagenary part of complex number
*/
void Complex :: setImage(int i) {
    image = i;
}

/*
    Get function for real part of complex number
*/
int Complex :: getReal() {
    return real;
}

/*
    Get function for imagenary part of complex number
*/
int Complex :: getImage() {
    return image;
}
