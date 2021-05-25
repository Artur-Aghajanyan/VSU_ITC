#include <iostream>
#include <memory.h>

template <class T, class Container = Vector<T>>
class Stack{
    private:
        unsigned int size;
        List<T> l1;
        Vector<T> v1;
        int type;

    public:
        Stack();
        explicit Stack( Container& ctnr);
        Stack(const Stack<T>& a);
        void push(T last);
        void pop();

        T &top();

        bool empty();
        int Size();
        ~Stack();
};

//Constructors
template <class T, class Container>
Stack<T,Container>::Stack() {
    size = 0;
    type = 16;
}

template <class T, class Container>
Stack<T,Container>::Stack( Container& ctnr) {
    type = sizeof(ctnr);
    if(sizeof(ctnr) == 16) {
       this -> size = ctnr.Size();
       for(int i = 0; i< size; ++i) {
            v1.push_back(ctnr[i]);
       }
    }
    else if(sizeof(ctnr) == 24) {
        this -> size = ctnr.Size();
        for(int j = 0; j < this ->size; ++j){
            l1.push_back(ctnr[j]);
        }
    }
}

template <class T, class Container>
Stack<T, Container>::Stack(const Stack<T>& a) {
    this -> size = a.size;
    this -> stack = new T[size];
    for(int i = 0; i < size-1; ++i) {
        this -> stack[i] = a.stack[i];
    }
}

//push
template <class T, class Container>
void Stack<T, Container>::push(T last) {
    if(type == 16) {
        v1.push_back(last);
        ++size;
    }
    else if(type == 24) {
        l1.push_back(last);
        ++size;
    }
}

//pop
template <class T, class Container>
void Stack<T, Container>::pop() {
    if(type == 16) {
        v1.pop_back();
        --size;
    }
    else if(type == 24) {
        l1.pop_back();
        --size;
    }
}

//top
template <class T, class Container>
T &Stack<T, Container>::top() {
    if(type == 16) {
        return v1[size-1];
    }
    else if(type == 24) {
        return l1[size-1];
    }
}

//empty
template <class T, class Container>
bool Stack<T, Container>::empty() {
    if(size == 0) {
        return true;
    }
    else return false;
}

//size
template <class T, class Container>
int Stack<T, Container>::Size() {
    return size;
}

//destructor
template <class T, class Container>
Stack<T, Container>::~Stack() {
}
