#ifndef COMPLEX_H
#define COMPLEX_H


 class Complex{
	public:
		 int real;
		 int image;
	public:
    	Complex();
		Complex(int real1,int image);
        Complex(const Complex& obj); 

        int staticfu();


		friend Complex operator+(const Complex obj1, const Complex  obj2);
		friend Complex operator-(const Complex obj1, const Complex  obj2);
		friend Complex operator*(const Complex obj1, const Complex  obj2);
        friend std::ostream& operator<<(std::ostream&  output, const Complex obj);
		friend std::istream& operator>> (std::istream& input, Complex& obj);
};


Complex operator+(const Complex obj1, const Complex  obj2);
Complex operator-(const Complex obj1, const Complex  obj2);
Complex operator*(const Complex obj1, const Complex  obj2);
std::ostream& operator<<(std::ostream& output, const Complex obj);
std::istream& operator>>(std::istream& input,  Complex& object);
#endif
