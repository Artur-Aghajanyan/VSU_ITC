#include <iostream>
#include <iterator>
#include <vector>

class Person {
    public:
        int age;
        int height;
        Person();
        Person(int a);
        Person(int a, int h);
        void operator=(const Person& p);

};

Person::Person() {
    age = 0;
    height = 0;
}

Person::Person(int a) {
    age = a;
    height =0;
}

Person::Person(int a, int h) {
    age = a;
    height = h;
}

void Person::operator = (const Person& p ) {
         this -> age = p.age;
         this -> height = p.height;
}

template <class T>
class MyVector : public std::vector<T> {
    public:
       void my_sort(std::string key);
       void print();
};

template <class T>
void MyVector<T>::my_sort(std::string key) {
    MyVector<Person>::iterator ptr1;
    MyVector<Person>::iterator ptr2;
    
    if(key == "age") {
        for (ptr1 = this -> begin(); ptr1 < this -> end(); ptr1++) { 
            for (ptr2 = this -> begin(); ptr2 < this -> end()-1; ptr2++) { 
                if(ptr2 -> age > (ptr2+1) -> age) {
                    Person p;
                    p = *ptr2;
                    *ptr2 = *(ptr2+1);
                    *(ptr2+1) = p;
                }
            }
        }    
    }
    else if(key == "height") {
        for (ptr1 = this -> begin(); ptr1 < this -> end(); ptr1++) { 
            for (ptr2 = this -> begin(); ptr2 < this -> end(); ptr2++) { 
                if(ptr2 -> height > (ptr2+1) -> height) {
                    Person p;
                    p = *ptr2;
                    *ptr2 = *(ptr2+1);
                    *(ptr2+1) = p;
                }
            }
        } 
    }   
}

template <class T>
void MyVector<T>::print() {
    MyVector<Person>::iterator ptr3;
    for(ptr3 = this -> begin(); ptr3 < this -> end(); ptr3++) {
        std::cout << "age: " << ptr3 -> age << ", height: " << ptr3 -> height <<std::endl;
    }
}
