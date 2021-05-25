#include <iostream>
#include <memory.h>

template <class T>
class Stack{
    private:
        int size;
        T *stack;
    public:
        Stack();
        Stack(const Stack& a);
        void push(T last);
        void pop();

        T &top();

        void swap(Stack &a);

        bool empty();
        int Size();
        ~Stack();
};

//Constructors
template <class T>
Stack<T>::Stack() {
    size = 0;
    stack = nullptr;
}

template <class T>
Stack<T>::Stack(const Stack& a) {
    this -> size = a.size;
    this -> stack = new T[size];
        for(int i = 0; i < size-1; ++i) {
            this -> stack[i] = a.stack[i];
        }
}

//push
template <class T>
void Stack<T>::push(T last) {
    T* newstack = new T[size+1];
    for(int i = 0; i < size; ++i) {
        newstack[i] = stack[i];
    }
    delete[] stack;
    newstack[size] = last;
    stack = newstack;
    ++size;    
}

//pop
template <class T>
void Stack<T>::pop() {
    if(size) {
        T* newstack = new T[size-1];
        for(int i = 0; i < size-1; ++i) {
            newstack[i] = stack[i];
        }
        delete[] stack;
        stack = newstack;
        --size;
    }
}

//top
template <class T>
T &Stack<T>::top() {
    return stack[size-1];
}

//empty
template <class T>
bool Stack<T>::empty() {
    if(size == 0) {
        return true;
    }
    else return false;
}

//size
template <class T>
int Stack<T>::Size() {
    return size;
}

//swap
template <class T>
void Stack<T>::swap(Stack &a){
    int fsize = this -> size;
    std::cout << "fs  " << fsize << std::endl;
    T* first = new T[fsize];
    for(int i = 0; i < fsize; ++i) {
        first[i] = this->stack[i];
    };

    int ssize = a.size;
    std::cout << "ss  " << ssize << std::endl;
    T* second = new T[ssize];
    for(int i = 0; i < ssize; ++i) {
       second[i] = a.stack[i];
    }
    delete[] this -> stack;
    delete[] a.stack;
    this->size = ssize;
    a.size = fsize;
    this -> stack = second;
    a.stack = first; 
}

//destructor
template <class T>
Stack<T>::~Stack() {
    delete[] stack;
}
