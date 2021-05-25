#include <iostream>
#include "complex.h"

Complex::Complex(){
		real = 0;
		image = 0;
}
Complex::Complex(int real1, int image1){
		real = real1;
		image = image1;
}



 int  Complex::staticfu(){
		 static int x=7;
		 ++x;
		 return x;

 }


Complex::Complex(const Complex& obj){
		this->real = obj.real;
		this->image = obj.image;

}

Complex operator+(const Complex obj1, const Complex  obj2){

		 Complex temp;
		 temp.real = obj1.real + obj2.real;
		 temp.image = obj1.image + obj2.image;
		 return temp;
}	

Complex operator-(const Complex obj1, const Complex  obj2){
 
         Complex temp;
         temp.real = obj1.real - obj2.real;
         temp.image = obj1.image - obj2.image;
         return temp;
}

Complex operator*(const Complex obj1, const Complex  obj2){
		 Complex temp;
	     temp.real = (obj1.real*obj2.real) - (obj1.image*obj1.image);
		 temp.image = (obj1.real*obj2.image) + (obj1.image*obj2.real);
		 return temp;
}		 

std::ostream& operator<<(std::ostream& output, const Complex obj){
		 output << obj.real <<'+'<< obj.image <<'i' << "\n";
		 return output;

}			

std::istream& operator>> (std::istream& input, Complex& object){
         input >> object.real >>  object.image;
		 return input;
}		 




