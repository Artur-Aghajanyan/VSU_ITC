#include <iostream>
#include<iterator>
#include <memory.h>
#include <initializer_list>

template <class T>
class Vector{
    private:
        int size;
        T *vector;
    public:
        Vector();
        Vector(int size);
        Vector(int size, T value);
        Vector(const Vector& a);
        void push_back(T last);
        void pop_back();
        bool empty();
        void print();
        void insert(int position, T val);
        void insert(int position, int quantity, T val);
        int Size();
        T &operator[](int i);
        ~Vector();
};

//Constructors
template <class T>
Vector<T>::Vector() {
    size = 0;
    vector = nullptr;
}

template <class T>
Vector<T>::Vector(int size) {
    this -> size = size;
    vector = nullptr;
}

template <class T>
Vector<T>::Vector(int size, T value) {
    this -> size = size;
    vector = new T[size];
    for(int i = 0; i < size; ++i) {
        vector[i] = value;
    }
}

template <class T>
Vector<T>::Vector(const Vector& a) {
    this -> size = a.size;
    this -> vector = new T[size];
    memcpy(this -> vector, a.vector, size*4);
}

//operator []
template <class T>
T& Vector<T>::operator[](int i) {
    if(i > size) {
        std::cout << "Not valid index" << std::endl;
        return vector[0];
    }
    return vector[i];
}

//print
template <class T>
void Vector<T>::print() {
    for(int i = 0; i < size; ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

//push_back
template <class T>
void Vector<T>::push_back(T last) {
    T* newvector = new T[size+1];
    memcpy(newvector, vector, (size)*sizeof(T));
    delete[] vector;
    newvector[size] = last;
    vector = newvector;
    ++size;    
}

//pop_back
template <class T>
void Vector<T>::pop_back() {
    if(size) {
        T* newvector = new T[size-1];
        memcpy(newvector, vector, (size-1)*sizeof(T));
        delete[] vector;
        vector = newvector;
        --size;
    }
}

//empty
template <class T>
bool Vector<T>::empty() {
    if(size == 0) {
        return true;
    }
    else return false;
}

//insert
template <class T>
void Vector<T>::insert(int position, T val) { 
        T* newvector = new T[size+1];
        if(position != 0) {
            for(int i = 0; i < position; ++i) {
                newvector[i] = vector[i];
            }
        }
        newvector[position] = val;
        for(int i = position; i < size; ++i) {
            newvector[i+1] = vector[i];
        }
        delete[] vector;
        vector = newvector;
        ++size;
}

template <class T>
void Vector<T>::insert(int position, int quantity, T val) {
    int for_while = quantity;
    T* newvector = new T[size+2];
    if(position != 0) {
        for(int i = 0; i < position; ++i) {
            newvector[i] = vector[i];
        }
    }
    while(for_while) {
        newvector[position + for_while - 1] = val;
       --for_while;
    }
    for(int i = position; i < size; i++) {
        newvector[i+quantity] = vector[i];
    }
    delete[] vector;
    vector = newvector;
    size = size + quantity;
}

//size
template <class T>
int Vector<T>::Size() {
    return size;
}


//destructor
template <class T>
Vector<T>::~Vector() {
    delete[] vector;
}
