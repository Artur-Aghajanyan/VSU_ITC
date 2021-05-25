#include <iostream>

class Complex {
	public:
		int real;
		int image;
		Complex(){
			real = 0;
			image = 0;
		}
		
		Complex(int real1 , int image1){
			real = real1;
			image = image1;
		}
		// coppy constructor
		Complex(const Complex& obj){
			this->real = obj.real;
			this->image = obj.image;
		}
		// static function
		int func(){
			static int x = 0;
			++x;
			return x;
		}
		friend Complex operator+(const Complex obj, const Complex comp);
		friend Complex operator-(const Complex obj, const Complex comp);
		friend Complex operator*(const Complex obj, const Complex comp);
		friend std ::ostream& operator<<(std::ostream& print, const Complex comp);
        friend std :: istream& operator>>(std::istream& input, Complex &in);
};
		// + operator
		Complex operator+(const Complex obj , const Complex comp) {
			Complex temp;
			temp.real = obj.real + comp.real;
			temp.image = obj.image + comp.image;
			return temp;
		}
		// - operator
		Complex operator-(const Complex obj , const Complex comp){
			Complex temp;
			temp.real = obj.real - comp.real;
			temp.image = obj.image - comp.image;
			return temp;
		}
        // (x1 + i*y1) * (x2 + i*y2) = (x1*x2-y1*y2) + i*(x1*y2+x2*y1)
        //  * operator
		Complex operator*(const Complex obj , const Complex comp){
			Complex temp;
			temp.real = (obj.real * comp.real)-(obj.image * comp.image);
		    temp.image = (obj.real * comp.image)+(obj.image * comp.real);
			return temp;
		}
				
std ::	ostream& operator<<(std::ostream& print, const Complex comp){
			print << comp.real <<" +" << comp.image <<"i" <<std::endl;
			return print;
		}

std :: istream& operator>>(std::istream& input, Complex &in) { 
         input >> in.real >> in.image;
         return input;            
      }	

int main(){

	Complex complex1(0, 0);
	Complex complex2(0, 0);
	Complex result1 = complex1;
    Complex result2;
    Complex	result3;
	std::cin >> complex1 >> complex2;  //cin
	result1 = complex1 + complex2;
	result2 = complex1 - complex2;
	result3 = complex1 * complex2;
	std::cout << result1;
	std::cout << result2;
	std::cout << result3;
	return 0;
}
