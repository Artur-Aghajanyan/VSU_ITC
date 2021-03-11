#include <iostream>

class Person {
    public:
        int age;
        double* data;
   
        Person() {
            std :: cout << "working default constructor" << std :: endl;
            age = 10;
            data = new double[10];
            for(int i = 0; i < 10; i++) {
                data[i] = i;
            }
        }
        Person(Person& obj) {
            std :: cout << "working copy constructor" << std :: endl;
            age = obj.age;
            data = new double[10];
            for(int i = 0; i < 10; i++) {
                data[i] = obj.data[i];
            }
        }
};

int main() {
    Person obj_def;
    Person obj_copy = obj_def;
    obj_def.data[0] = 10;
    std :: cout << obj_def.data[0] << std :: endl;
    std :: cout << obj_copy.data[0] << std :: endl;
    return 0;
}