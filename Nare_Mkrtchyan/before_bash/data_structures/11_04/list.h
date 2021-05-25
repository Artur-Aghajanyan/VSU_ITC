#include <iostream>

template <class T>
class List {
    unsigned int size;
    struct Node {
        T val;
        Node* prev;
        Node* next;
    };
    Node* begin;
    Node* end;
    public:
        List();
        void push_back(T a);
        void push_front(T a);
        void insert(int index, T a);

        void pop_back();
        void pop_front();
        void erase(int index);
        void print();
        unsigned int Size();
        bool empty();
        T &operator[](int i);
};

//constructor
template <class T>
List<T>::List() {
    size = 0;
    begin = nullptr;
    end = nullptr;
}

template <class T>
T& List<T>::operator[](int i) {
    if(i > size) {
        std::cout << "Not valid index" << std::endl;
        return begin -> val;
    }
    else {
        Node* elem = begin;
        for(int j = 0; j < i; j++){
            elem = elem -> next;
        }
      //  std::cout << "Not valid index: " << elem -> val << std::endl;
        return elem -> val;
    }
}


//size, empty
template <class T>
unsigned int List<T>::Size() {
    return size;
}

template <class T>
bool List<T>::empty() {
    if(begin == nullptr) {
        return true;
    }
    else return false;
}

//push,insert
template <class T>
void List<T>::push_back(T a) {
    Node* node = new Node;
    node -> val = a;
    node -> next = nullptr;
    node -> prev = nullptr;
    Node* el = begin;
    if(!end) {
        begin = node;
        end = node;
    }
    else {
    while(el&&el -> next) {
        el = el -> next;
    }
        el -> next = node;
        node -> prev = el;
        end = node;
    }
    ++size;
}

template <class T>
void List<T>::push_front(T a) {
    Node* node = new Node;
    node -> val = a;
    node -> next = nullptr;
    node -> prev = nullptr;
    if(begin) {
    Node* el = begin;
        begin = node;
        node -> next = el;
    }
    else {
        begin = node;
        end = node;
    }
    ++size;
}

template <class T>
void List<T>::insert(int index, T a) {
    Node* node = new Node;
    node -> val = a;
    node -> next = nullptr;
    node -> prev = nullptr;

    Node* toins = begin;

    if(index == 0){
        begin = node;
        node -> next = toins;
        return;
    }
    if(index == 1){
        Node* bn = begin -> next;
        begin -> next = node;
        bn -> prev = node;
        node -> next = bn;
        node -> prev = begin;
    }
    else{
        for(int i = 1; i < index; i++){
            toins = toins -> next;
        }
    }
    Node* nexti = toins -> next;
    toins -> next = node;
    node -> prev = toins;
    node -> next = nexti;
    node -> next -> prev = node;

    ++size;
}

//pop, erase
template <class T>
void List<T>::pop_back() {
    if(end == begin) {
        Node* el = begin;
        Node* el1 = end;
        delete begin;
        end = nullptr;
        begin = nullptr;
        --size;
    }
    if(end) {
        Node* el = end -> prev;
        delete end;
        end = el;
        end -> next = nullptr;
       --size;
    }
}

template <class T>
void List<T>::pop_front() {
    if(end == begin) {
        Node* el = begin;
        Node* el1 = end;
        delete begin;
        end = nullptr;
        begin = nullptr;
        --size;
    }
    if(end) {
        Node* el = begin -> next;
        delete begin;
        begin = el;
        begin -> prev = nullptr;
       --size;
    }
}

template <class T>
void List<T>::erase(int index){
    Node* elem = begin;

    if(index==0){
        Node* todel = elem -> next;
     delete elem;
     todel -> prev = nullptr;
     begin = todel;
        return;
    }

    else if(index == 1){
      //  Node<T>* todel = elem -> next;
       // Node<T>* nto = todel -> next;
    }
    else {
    for(int i = 1; i < index; i++){
        elem = elem -> next;
    }
    }
    Node* todel = elem -> next;
    Node* nto = todel -> next;
    delete todel;
    elem -> next = nto;
    elem -> next -> prev = elem;
    --size;
}

//print
template <class T>
void List<T>::print() {
    Node* el = begin;
    while(el && el->next) {
        std::cout << el -> val << std::endl;
        el = el -> next;
    }   
    if(end) {
        std::cout << end -> val <<std::endl;
    }
}
