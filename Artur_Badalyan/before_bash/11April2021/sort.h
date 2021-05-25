#include <iostream>
#include <vector>
using namespace std;


class Person {
	public:
	int age;
	int height;		
	Person();
	Person(int age,int height);
	~Person();	
	void operator = (const Person& person);

};

template <class T>
class customVector : public vector<Person> {
		public:
		void sortBy(string key);
		void print();
				
};



Person::Person(){
this->age = 0;
this->height = 0;
}


Person::Person(int age,int height){
this->age = age;
this->height = height;
}


Person::~Person(){}


void Person::operator = (const Person& person) {
	this->age = person.age;
	this->height = person.height;
}

template <class T>
void customVector<T>::sortBy(string key) {
	customVector<Person>::iterator ptr;
	customVector<Person>::iterator ptr2;	
	
	if (key == "age") {
		for (ptr = begin(); ptr < end();++ptr) {
			for(ptr2 = begin();ptr2 < end()-1;++ptr2) {
				if (ptr2->age > (ptr2 + 1)->age) {
				Person temp = *ptr2;
				*ptr2 = *(ptr2+1);
				*(ptr2+1) = temp;
				}
			}
		}
		cout << endl;
	}else if (key == "height") {
		for (ptr = begin(); ptr < end();++ptr) {
			for(ptr2 = begin();ptr2 < end()-1;++ptr2) {
				if (ptr2->height > (ptr2 + 1)->height) {
				Person temp = *ptr2;
				*ptr2 = *(ptr2+1);
				*(ptr2+1) = temp;
				}
			}
		}
		cout << endl;
	}else {
	cout << "We write wrong key!!\n";
	}	
	
}

template <class T>
void customVector<T>::print() {
	customVector<Person>::iterator ptr;
	for (ptr = begin();ptr < end();++ptr) {
		cout <<"Age - "<< ptr->age << " Height - "<<ptr->height<<endl;
	}
}
