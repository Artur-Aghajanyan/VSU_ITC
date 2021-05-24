#include <iostream>

#include "comp.h"

/* Default constructor */
template <class T>
Complex<T>::Complex() {
    real = 0;
    image = 0 ;
}

/* Parametrize constructor */
template <class T>
Complex<T>::Complex(T a, T b) {
    real = a;
    image = b;

}

/* Copy constructor */
template <class T>
Complex<T>::Complex(const Complex<T> &obj) {
    real = obj.real;
    image = obj.image;
}

/* Getter */
template <class T>
T Complex<T>::getReal() {
    return real;
}

template <class T>
T Complex<T>::getImage() {
    return image;
}

/* Setter */
template <class T>
void Complex<T>::setReal(T a) {
    this -> real = a;
}

template <class T>
void Complex<T>::setImage(T b) {
    this -> image = b;
}

/* Overloaded operators */
template <class T>
Complex<T> Complex<T>::operator + (const Complex<T> &obj) {
    Complex sum;
    sum.real = real + obj.real;
    sum.image = image + obj.image;
    return sum;
}

template <class T>
Complex<T> Complex<T>::operator - (const Complex<T> &obj) {
    Complex diff;
    diff.real = real - obj.real;
    diff.image = image - obj.image;
    return diff;
}

template <class T>
Complex<T> Complex<T>::operator * (const Complex<T> &obj) {
    Complex mul;
    mul.real = real * obj.real - image * obj.image;
    mul.image = real * obj.image + image * obj.real;
    return mul;
}

/* Friend functions */
template <class T>
std::istream& operator >> (std::istream &cin, Complex<T> &obj) {
    std::cout << "Enter real part of complex number : ";
    cin >> obj.real;
    std::cout << "Enter image part of complex number : ";
    cin >> obj.image;
    return cin;
}

template <class T>
std::ostream& operator << (std::ostream &cout, const Complex<T> &obj) {
    if(obj.real == 0 && obj.image == 0) {
        return cout << 0;
    } else if(obj.real == 0) {
        return cout << obj.image << "i";
    } else if(obj.image == 0) {
        return cout << obj.real;
    } else if(obj.image < 0) {
        return cout << obj.real << "" << obj.image << "i";
    }else {
        return cout << obj.real << "+" << obj.image << "i";
    }
}


