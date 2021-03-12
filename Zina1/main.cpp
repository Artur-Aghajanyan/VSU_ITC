#include <iostream>
#include <memory.h>

class Person {
	public:
	int age;
	double* data;
	Person () { 
		age = 15;
		data = new double[10];
		for (int i = 1; i <= 10; i++) {
			data[i - 1] = i;
	        }
	}
	Person (int a) {
		age = a;
	}
	Person (const Person &p) {
		this -> age = p.age;
		this -> data = new double [10];
		memcpy (this -> data, p.data, 80);
        }	
};

int main () {
	Person p, p1 = p;
	for (int i = 0; i < 10; i++) {
		std::cout << p.data[i] << "\n";
	}
	std :: cout << p.age << "\n" << p1.age << "\n";
	p1.data[5] = 30;
	for (int i = 0; i < 10; i++) {
                std::cout << p.data[i] << " " << p1.data[i] << "\n";
        }

	return 0;
}
