#include <iostream>

template <class T>
class Complex
{
    private:
        T real;
        T  image;
    public:
        static int   count;//static variable of class
        Complex();//definition of default constructor
        Complex(T r, T i);//definition ob parametrized constructor
        Complex(const Complex<T> &c);//definition of copy constructor
//definition of input and output functions for overloading
template <class V>
	friend std::ostream& operator<<  (std::ostream& out, const Complex<V> &c);
template <class V>
	friend std::istream& operator>>   (std::istream &in,  Complex<V> &c);
template <class V>
	//definition of functions for overloading arithmetic operations
	friend Complex<V> operator+ ( Complex<V> const &, Complex<V> const &);
template <class V>
	friend Complex<V> operator-  (Complex<V> const &a,  Complex<V> const &b);
template <class V>
	friend Complex<V> operator*   (Complex<V> const &c1, Complex<V> const &c2);
};
template <class T>
	int Complex<T>::count=0;

//default constructor, which initialize complex number 0+0i
template < class T>
	Complex<T>::Complex ()
{
		real = 0;
		image = 0;
}
														
//constructer with parametr to initialize complex number
template < class T>
	Complex<T>::Complex(T r, T i)
{
		real = r;
		image = i;
		++count;
}
//copy constructer
template < class T>
	Complex<T>::Complex(const Complex<T> &c){
		this->real = c.real;
		this->image = c.image;
}
//overload output  operator for complex number
template < class V>
	std::ostream & operator << (std::ostream &out, const Complex<V> &c) 
{ 
    	out << "("<<c.real<<")"; 
    	out  <<"+"<<"("<< c.image<<")"<< "i"; 
    	return out; 
} 
 // overload input operator for real and image parts of complex number
template < class V>
	std::istream & operator >> (std::istream &in,  Complex<V> &c) 
{ 
		std::cout << "Input  real "; 
    	in >> c.real; 
    	std::cout << "Input  image"; 
    	in >> c.image; 
    	return in; 
} 
//overload addition operator for complex number
template < class V>
	Complex<V>  operator+ ( Complex<V> const &a, Complex<V> const &b){
		Complex<V> n;
		n.real = a.real+b.real;
		n.image = a.image+b.image;
		return n;
}
//overload subtraction operator for complex number
template < class V>
	Complex<V>   operator- (Complex<V> const &a, Complex<V> const &b)
{
		Complex<V> m;
		m.real = a.real-b.real;
		m.image = a.image-b.image;
		return m;
}
//overload multiplication operator for complex numeber
template < class V>
	Complex<V> operator* (Complex<V> const &c1, Complex<V> const &c2)
{
		Complex<V> t;
		t.real = c1.real*c2.real-c1.image*c2.image;
		t.image = c1.real*c2.image+c2.real*c1.image;
		return t;
}
