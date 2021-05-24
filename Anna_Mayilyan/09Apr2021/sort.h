#include <iostream>
#include <vector>

class Person{
	public:
	int age;
	int haigth;
	Person();
	Person(int  a, int h );
	~Person();
	void operator = (const Person& p);
};

Person::Person(){
	age = 0;
	haigth = 0;
}

Person::Person(int a, int h)
{
	age = a;
	haigth = h;
}
Person::~Person(){};

void Person::operator = (const Person& p){
	age = p.age;
	haigth = p.haigth;
}
template <class T>
class AVector: public std::vector<T>{
	public:
	void Sort(std::string by);
	void print();
};

template <class T>
void AVector<T>::print(){
	AVector<Person>::iterator ptr;
	for(ptr = this->begin(); ptr < this ->  end(); ptr++){
		std::cout<<"age: "<<ptr->age<<" heigth:  "<<ptr->haigth<<std::endl;
	}
}
template <class T>
void AVector<T>::Sort(std::string by){
	 AVector<Person>::iterator i;
	 AVector<Person>::iterator j;
	for(i = this->begin(); i < this -> end(); i++){
		for(j = this->begin(); j < this -> end()-1; j++){
			if(j->age > (j+1)->age && by == "age"){
				Person obj;
				obj = *j;
				*j = *(j+1);
				*(j+1) = obj;
			}
			 if(j->haigth > (j+1)->haigth && by == "haigth"){
				
                Person obj;
                obj = *j;
                *j = *(j+1);
                *(j+1) = obj;
			}
		}
	}	
}

