/*
 * Made class Complex and overload operators (<<,>>,+,-,*). 
 * Made getter and setter for class Complex. 
 * */


#include <iostream>
#include <fstream>


template <class T>
class Complex{
		
		private:
		T real;
		T imag;

		public:		
		Complex();
		Complex(T real,T imag);
		Complex(const Complex& complex);
        
		template <class T1> friend std::ostream& operator<< (std::ostream& cpl,const Complex<T1>& complex);
		template <class T2> friend std::istream& operator>> (std::istream& cpl, Complex<T2>& complex);

		Complex<T> operator + (const Complex<T>& complex);
		Complex<T> operator - (const Complex<T>& complex);				
		Complex<T> operator * (const Complex<T>& complex);

		T realGett() const;
		T imagGett() const;
		void realSet(T r);
		void imagSet(T i);
};


// Default constructor
template <class T>
Complex<T>::Complex() {
	this->real = 0;
	this->imag = 0;
};

// Params constructor
template <class T>
Complex<T>::Complex(T real1,T imag1) {
	this->real = real1;
	this->imag = imag1;
}

// Copy constructor
template <class T>
Complex<T>::Complex(const Complex<T>& complex) {
	this->real = complex.real;
	this->imag = complex.imag;
}

// Overloading operator <<
template <class T1>
std::ostream& operator<<(std::ostream& os,const Complex<T1>& complex) {
	os << complex.real << " + " << complex.imag<<"i"<<std::endl;
	return os;
}

// Overloading operator >>
template <class T2>
std::istream& operator>>(std::istream& is, Complex<T2>& complex) {
	std::cout<< "enter real number"<<std::endl;	
	is >> complex.real;
	std::cout<< "enter imag number"<<std::endl;
   	is >> complex.imag;
	return is;	
}

// Overloading operator +
template <class T>
Complex<T> Complex<T>::operator + (const Complex<T>& complex) {
	Complex temp;
	temp.real = this->real + complex.real;
	temp.imag = this->imag + complex.imag;
	return temp;
}

// Overloading operator -
template <class T>
Complex<T> Complex<T>::operator - (const Complex<T>& complex) {
	Complex temp;
	temp.real = this->real - complex.real;
	temp.imag = this->imag - complex.imag;
	return temp;
}

// Overloading operator *
template <class T>
Complex<T> Complex<T>::operator * (const Complex<T>& complex) {
    Complex temp;
    temp.real = real * complex.real - imag * complex.imag;
    temp.imag = (real * complex.imag) + (complex.real * imag);
    return temp;
}

// Getters and Setters
template <class T>
T Complex<T>::realGett() const {
	return this->real;
}

template <class T>
T Complex<T>::imagGett() const {
	return this->imag;
}

template <class T>
void Complex<T>::realSet(T r) {
	this->real = r;	
}

template <class T>
void Complex<T>::imagSet(T i) {
	this->image = i;
}

