#include <iostream>
#include "vector.h"


Vector::Vector() {
    this->size = 0;
    array = new int[size];    
}

Vector::Vector(int size) {
    this->size = size;
    array = new int[size];
}

Vector::Vector(int size,int value) {
    this->size = size;
    for(int i = 0;i <= size;i++){
        array[i] = value;
    }
}

Vector::Vector(const Vector &other){
    copy(array,array+size,other.array);
}

Vector::~Vector(){
    delete[] array;
}


int &Vector::operator[](int i){
    if (i > size){
        std::cerr << "Error! Index out of bounds" <<std::endl;
    }
    return array[i];
}

void Vector::push_back(int value){
    int *newArray = new int[size + 1];
    std::copy(array,array+size,newArray);
    newArray[size] = value;
	++size;
    delete[] array;
    array = newArray;
}

int Vector::pop_back() {
    int *newArray = new int[size - 1];
    std::copy(array,array+size-1,newArray);
	--size;
    delete[] array;
    array = newArray;
}

void Vector::insert(int index,int value){
    int *newArray = new int[size + 1];
    std::copy(array,array+index,newArray);
    newArray[index] = value;
    std::copy(array+index+1,array+size,newArray+index+1);
	++size;
    delete[] array;
    array = newArray;
}

int Vector::vec_size() {
    return this->size;
}

bool Vector::empty(){
    if (size == 0){
        return false;
    }
    return true;
}
    
