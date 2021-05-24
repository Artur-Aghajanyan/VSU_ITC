#include <iostream>

template <class T>
struct Node{
    Node* next;
    T value;
};

template <class T>
class List{
    public:
        List();
        void push(T a);
        void print();
        void pop();
        void erase(int index);
        void insert(int index, T a);


        int &operator[](int i);

    private:
        Node<T>* begin;
        int size;
};

template <class T>
int& List<T>::operator[](int i){
          if(i >= size){
              std::cout<<"Invalid index"<<std::endl;
              exit(0);
          }
          else{
              Node<T>* ret = begin;
             for(int j=1; j < i+1; j++){
                  ret = ret -> next;
              }
          return ret -> value;
          } 
}


template <class T>
List<T>::List(){
    begin = nullptr;
    size = 0;
}

template <class T>
void List<T>::push(T a){
    Node<T>* node = new Node<T>;
    node -> value = a;
    node -> next = nullptr;

    Node<T>* end = begin;

    while(end && end -> next){
        end = end -> next;
    }

    if(!end){
       begin = node;
    }
    else{
        end -> next = node;
    
    }
        ++size;
    
}

template <class T>
void List<T>::print(){
    Node<T>* elem = begin;
if(size == 0){
    return;
}
    while(elem && elem -> next){
        std::cout<<elem -> value<<std::endl;
    elem = elem -> next;
    }
         std::cout<<elem -> value<<std::endl;

}

template <class T>
void List<T>::pop(){
    Node<T>* end = begin;
    if(size==0){
        return;
    }

    else if(size == 1){
        delete end;
        begin = nullptr;
        --size;
        return;
    }
    for(int i = 1; i < size - 1; i++){
        end = end -> next;
    }
    delete end -> next;
    end -> next = nullptr;
    --size;
}

template <class T>
void List<T>::erase(int index){
    Node<T>* elem = begin;

    if(index==0){
        Node<T>* todel = elem -> next;
     delete elem;
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
    Node<T>* todel = elem -> next;
    Node<T>* nto = todel -> next;
    delete todel;
    elem -> next = nto;
    --size;

}


template <class T>
void List<T>::insert(int index, T a){
    Node<T>* node = new Node<T>;
    node -> value = a;
    node -> next = nullptr;

    Node<T>* toins = begin;

    if(index == 0){
        begin = node;
        node -> next = toins;
        return;
    }
    if(index == 1){
        
    }
    else{
        for(int i = 1; i < index; i++){
            toins = toins -> next;
        }
    }
    Node<T>* nexti = toins -> next;
    toins -> next = node;
    node -> next = nexti;

    ++size;
}
