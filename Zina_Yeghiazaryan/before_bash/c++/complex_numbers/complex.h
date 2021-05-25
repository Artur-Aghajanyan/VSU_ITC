#include <ostream>
#include <istream>

class Complex {
	private:
		int real;
		int image;
	public:
		/*
		    Constructors
		*/
		Complex();
		Complex(int real, int image);
		Complex(const Complex& number2);
		
		/*
		    <<, >>, +, -, * operators overloaded
		*/
		friend std :: ostream& operator << (std :: ostream& output, const Complex& number);
		friend std :: istream& operator >> (std :: istream& input, Complex& number);
		Complex operator + (const Complex& number);
		Complex operator - (const Complex& number);
		Complex operator * (const Complex& number);
		
		/*
		    Functions
		*/
		void setReal(int r);
		void setImage(int i);
		int getReal();
		int getImage();
};
