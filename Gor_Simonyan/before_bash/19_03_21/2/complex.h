#include <iostream>
template<class T>
class Complex
{
	T real;
	T imag;
	public:
		Complex()	//default constructor
		{
        		real = 0;
        		imag = 0;
		};

		Complex(T r,T i)	//arguments constructor
		{
        		real = r;
        		imag = i;
		};

		Complex(const Complex& c)	//copy constructor
		{
        		real = c.real;
        		imag = c.imag;
		};

		Complex operator+(const Complex& a)	//overloading op. +
		{
        		Complex n;
        		n.real = this->real + a.real;
        		n.imag = this->imag + a.imag;
        		return n;
		};

		Complex operator-(const Complex& b)	//overloading op. -
		{
        		Complex n;
        		n.real = this->real - b.real;
        		n.imag = this->imag - b.imag;
        		return n;
		};

		Complex operator*(const Complex& c)	//overloading op. *
		{
        		Complex n;
        		n.real = this->real * c.real - this->imag * c.imag;
        		n.imag = this->real * c.imag + c.real * this->imag;
       	 		return n;
		};

		friend std::ostream& operator<<(std::ostream &out, Complex &o)	//overloading op. <<
		{
                        out << o.real << "+" << o.imag << "i";
                        return out;
                };

		friend std::istream& operator>>(std::istream& in, Complex& i)	//overloading op. >>
		{
                        char oper;
                        char u;
                        in >> i.real >> oper >> i.imag >> u;
                        return in;
                };


};
