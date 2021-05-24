#include <iostream>
#include "complex.h"

/*
  Constructor witout paramerts
*/
template <class T>
Complex<T>::Complex() {
    real = 0;
    image = 0;
}

/*
  Constructor with parametrs
*/
template <class T>
Complex<T>::Complex(T a, T b) {
    real = a;
    image = b;
}

/*
  Copy constructor
*/
template <class T>
Complex<T>::Complex(const Complex<T>& a) {
    this -> real = a.real;
    this -> image = a.image;
} 

/*
 Overload operator+
*/ 
template <class T>
Complex<T> Complex<T>::operator+(const Complex<T>& a) {
    Complex<T> c;
    c.real = this -> real + a.real;
    c.image = this -> image + a.image;
    return c;
}

/*
 Overload operator-
*/
template <class T>
Complex<T> Complex<T>::operator-(const Complex<T>& a) {
    Complex<T> c;
    c.real = this -> real - a.real;
    c.image = this -> image - a.image;
    return c;
}

/*
 Overload operator*
*/ 
template <class T>
Complex<T> Complex<T>::operator*(const Complex<T>& a) {
    Complex<T> c;
    c.real = (this -> real * a.real)  - (this -> image * a.image);
    c.image = (this -> real * a.image) + (this -> image * a.real);
    return c;
}

/*
 Overload operator/
*/ 
template <class T>
Complex<T> Complex<T>::operator/(const Complex<T>& a) {
    Complex<T> c;
    if(a.real == 0 && a.image == 0) {
        std::cout << "Denominator can't be 0" << std::endl;
        return a;
    }

    T tr = this -> real;
    T ti = this -> image;
    T ar = a.real;
    T ai = a.image;
    T denominator = ar * ar + ai * ai;

    c.real = (tr * ar + ti * ai) / denominator;
    c.image = (tr * (-ai) + ti * ar) / denominator;
    return c;
}

template <class T>
void Complex<T>::setReal(T r) {
    real = r;
}  

template <class T>
void Complex<T>::setImage(T im) {
    image = im;
}

/*
 Getters
*/ 
template <class T>
T Complex<T>::getReal() {
    return real;
}

template <class T>
T Complex<T>::getImage() {
    return image;
}

template class Complex<int>;
template class Complex<double>;
