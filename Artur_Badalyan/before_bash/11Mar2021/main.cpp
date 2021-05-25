#include <iostream>
#include <memory>




class Person{
	public:
	Person(){
		
	this->age = 0;
	this->data = new double[10];	
	
	}

	Person(const Person &p){
		//memcpy(this->data, p.data, 80) // 80 = 10 * 8(byte for double)
		age = p.age;
		data = new double[10];

		for(int i = 0;i < 10;i++){
		
			data[i] = p.data[i];	

		}

	}
	int age;
	double* data;

};

int main(){

	Person p;
	for(int i=0;i < 10; i++){	
		p.data[i] = i;
		std::cout << "p data ------- " << p.data[i] << std::endl;

	}
	Person p1 = p;
	std::cout << "\n\n\n" << "--------------------------------------" << "\n\n\n";

	for(int i=0;i < 10; i++){
		
		p1.data[i] = i+10;

		std::cout << "p data ------- " << p.data[i] << std::endl;
		std::cout << "p1 data ------ " << p1.data[i] << std::endl;

	}
}
