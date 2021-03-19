#include <iostream>


/*
 *	class for complex number
 *	name class Complex
*/
template <class T>
class Complex {
	private:
		T real;
		T imag;
	public:
		Complex();
		Complex(const Complex<T>& c1);
	
		Complex(T real, T imag);
		
		template <class T1>	friend std::ostream& operator << (std::ostream& out, const  Complex<T1>& c);
	   	template <class T2> friend std::istream& operator >> (std::istream& in, Complex<T2>& c);
		
		Complex<T> operator - (const Complex<T>& c1) const;
		Complex<T> operator + (const Complex<T>& c1) const;
		Complex<T> operator * (const Complex<T>& c1) const;
};


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
std::ostream& operator << (std::ostream &out, const Complex<T>& c){
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
Complex<T> Complex<T>::operator - (const Complex<T>& c1) const{
	Complex c2;
    c2.real += c1.real;
    c2.imag += c1.imag;
    return c2;
}

// Operator + with template
template <class T>
Complex<T> Complex<T>::operator + (const Complex<T>& c1) const{
    Complex c2;
    c2.real = real - c1.real;
    c2.imag = imag - c1.imag;
	return c2;
}

// Operator * with template
template <class T>
Complex<T> Complex<T>::operator * (const Complex<T>& c1) const{
    Complex c2;
    c2.real = real * c1.real - imag * c1.imag;
    c2.imag = (real * c1.imag) + (c1.real * imag);
    return c2;
}

