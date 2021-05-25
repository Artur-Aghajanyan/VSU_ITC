#include <ostream>
#include <istream>

template <class T>
class Complex;
template <class T1>
std :: ostream& operator << (std :: ostream& output, const Complex<T1>& number);
template <class T1>
std :: istream& operator >> (std :: istream& input, Complex<T1>& number);

template <class T>
class Complex {
	private:
		T real;
		T image;
	public:
		/*
		    Constructors
		*/
		Complex();
		Complex(T real, T image);
		Complex(const Complex<T>& number2);
		
		/*
		    <<, >>, +, -, * operators overloaded
		*/
		template <class T1>
	    friend std :: ostream& operator << (std :: ostream& output, const Complex<T1>& number);
	    template <class T1>
		friend std :: istream& operator >> (std :: istream& input, Complex<T1>& number);
		Complex<T> operator + (const Complex& number);
		Complex<T> operator - (const Complex& number);
		Complex<T> operator * (const Complex& number);
		
		/*
		    Functions
		*/
		void setReal(T r);
		void setImage(T i);
		T getReal();
		T getImage();
};

/*
    Default constructor
*/
template <class T>
Complex<T> :: Complex() {
	real = 0;
	image = 0;
}

/*
    Parametrized constructor
*/
template <class T>
Complex<T> :: Complex(T real, T image) {
	this -> real = real;
	this -> image = image;
}

/*
    Copy constructor
*/
template <class T>
Complex<T> :: Complex(const Complex& number2) {
	this -> real = number2.real;
	this -> image = number2.image;
}

/*
    Overloaded output operator - <<
*/
template <class T>
std :: ostream& operator << (std :: ostream& output, const Complex<T>& number) {
	output << "Re = " << number.real << " Im = " << number.image << ' ';
	return output;
}

/*
    Overloaded input operator - >>
*/
template <class T>
std :: istream& operator >> (std :: istream& input, Complex<T>& number) {
	input >> number.real >> number.image;
	return input;
}

/*
    Overloaded addition (+) operator
*/
template <class T>
Complex<T> Complex<T> :: operator + (const Complex<T>& number) {
	Complex sum;
	sum.real = real + number.real;
	sum.image = image + number.image;
	return sum;
}

/*
    Overloaded subtraction (-) operator
*/
template <class T>
Complex<T> Complex<T> :: operator - (const Complex<T>& number) {
	Complex difference;
	difference.real = real - number.real;
	difference.image = image - number.image;
	return difference;
}

/*
    Overloaded multipliction (*) operator
*/
template <class T>
Complex<T> Complex<T> :: operator * (const Complex<T>& number) {
	Complex product;
	product.real = real * number.real - image * number.image;
	product.image = real * number.image + number.real * image;
	return product;
}
