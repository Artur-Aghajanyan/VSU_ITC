#include <iostream>
#include "complex.h"

/*
  Constructor witout paramerts
*/
Complex::Complex() {
    real = 0;
    image = 0;
}

/*
  Constructor with parametrs
*/
Complex::Complex(int a, int b) {
    real = a;
    image = b;
}

/*
  Copy constructor
*/
Complex::Complex(const Complex& a) {
    this -> real = a.real;
    this -> image = a.image;
}

/*
 Overload operator+
*/ 
Complex Complex::operator+(const Complex& a) {
    Complex c;
    c.real = this -> real + a.real;
    c.image = this -> image + a.image;
    return c;
}

/*
 Overload operator-
*/
Complex Complex::operator-(const Complex& a) {
    Complex c;
    c.real = this -> real - a.real;
    c.image = this -> image - a.image;
    return c;
}

/*
 Overload operator*
*/ 

Complex Complex::operator*(const Complex& a) {
    Complex c;
    c.real = (this -> real * a.real)  - (this -> image * a.image);
    c.image = (this -> real * a.image) + (this -> image * a.real);
    return c;
}

/*
 Overload operator/
*/ 
Complex Complex::operator/(const Complex& a) {
    Complex c;

    c.real = ((this -> real * a.real)  + (this -> image * a.image))/((a.real * a.real) + (a.image * a.image));
    c.image = ((this -> real * (-a.image))  + (this -> image * a.real))/((a.real * a.real) + (a.image * a.image));
    return c;
}

/*
 Overload operator<<
*/ 
std::ostream& operator<<(std::ostream& comp, const Complex& a) {
    if(a.real != 0) {
        if(a.image != 0 ) {
            if(a.image > 0) {
                return comp << a.real << "+" << a.image << "i";
            }
            else
                return comp << a.real << "" << a.image << "i";
            }
        else {
            return comp << a.real;
        }
    }
    else {
        return comp << a.image << "i";
    }

}

/*
 Overload operator<<
*/ 
std::istream& operator>>(std::istream& comp, Complex& a) {
    return comp >> a.real >> a.image;
}
