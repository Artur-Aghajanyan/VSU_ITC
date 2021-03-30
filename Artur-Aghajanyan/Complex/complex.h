#include <iostream>


/*
 *	class for complex number
 *	name class Complex
 *	it has 3 constructors: copy, params, default
 *	it has 5 operators integration: <<, >>, -, +, *
*/
/*template <class T>*/
class Complex {
	private:
		int real;
		int imag;
	public:
		Complex(); // default constructor
		Complex(const Complex& c1); // copy constructor
		Complex(int real, int imag); // params constructo
		
		int getReal() const; // getter thus->real
		int getImage() const; // getter this->imag

		void setReal(int r); // setter this->real
		void setImag(int i); // setter this->imag

		friend std::ostream& operator << (std::ostream& out, const  Complex& c); // Operator <<
		friend std::istream& operator >> (std::istream& in, Complex& c); // Operator >> 
		
		Complex operator - (const Complex& c1) const; // Operator -
		Complex operator + (const Complex& c1) const; // Operator +
		Complex operator * (const Complex& c1) const; // Operator *

/*	private:
		T real;
		T imag;
	public:
		Complex(); // default constructor
		Complex(const Complex<T>& c1); // copy constructor
		Complex(T real, T imag); // params constructo
		
		T getReal() const; // getter thus->real
		T getImage() const; // getter this->imag

		void setReal(T r); // setter this->real
		void setImag(T i); // setter this->imag

		template <class T1>	friend std::ostream& operator << (std::ostream& out, const  Complex<T1>& c); // Operator <<
	   	template <class T2> friend std::istream& operator >> (std::istream& in, Complex<T2>& c); // Operator >> 
		
		Complex<T> operator - (const Complex<T>& c1) const; // Operator -
		Complex<T> operator + (const Complex<T>& c1) const; // Operator +
		Complex<T> operator * (const Complex<T>& c1) const; // Operator *
*/
};


/* 
 * Start making functionality for class Complex 
 * With Template
 * */
/*
// Setter for this->real
template <class T>
void Complex<T>::setReal(T r) {
	this->real = r;
}

// Setter for this->imag
template <class T>
void Complex<T>::setImag(T i) {
	this->imag = i;
}

// Default Constructor
template <class T>
Complex<T>::Complex() {
	this->real = 0;
	this->imag = 0;
}


// Constructor with params, with tepmalte
template <class T>
Complex<T>::Complex(T x1, T y1) {
	this->real = x1;
	this->imag = y1;
}

// Copty constructor with template
template <class T>
Complex<T>::Complex(const Complex<T>& c) {
	this->real = c.real;
	this->imag = c.imag;
}

// Operator << with template
template <class T>
std::ostream& operator << (std::ostream &out, const Complex<T>& c) {
	out << c.real << " + " << c.imag <<"i"<< std::endl;
	return out;
}


// Operator >> with template
template <class T>
std::istream& operator >> (std::istream& in, Complex<T>& c) {
	std::cout << "Enter Real Part ";
	in >> c.real;
	std::cout << "Enter Imaginory Part ";
	in >> c.imag;
	return in;
}

// Operator - with template
template <class T>
Complex<T> Complex<T>::operator - (const Complex<T>& c1) const {
	Complex c2;
    c2.real += c1.real;
    c2.imag += c1.imag;
    return c2;
}

// Operator + with template
template <class T>
Complex<T> Complex<T>::operator + (const Complex<T>& c1) const {
    Complex c2;
    c2.real = real - c1.real;
    c2.imag = imag - c1.imag;
	return c2;
}

// Operator * with template
template <class T>
Complex<T> Complex<T>::operator * (const Complex<T>& c1) const {
    Complex c2;
    c2.real = real * c1.real - imag * c1.imag;
    c2.imag = (real * c1.imag) + (c1.real * imag);
    return c2;
}
*/
/* 
 * End making functionality for class Complex 
 * With Template
 * */
