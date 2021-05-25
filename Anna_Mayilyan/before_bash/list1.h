#include <iostream>
template <class T>
 struct Node{
        Node* next;
        T value;
};
template <class T>
 class List{
        public:
                List(){
                        begin=nullptr;
                        size=0;
                }
		void push(T a);
  
	T operator[](T index)
   {


Node<T>* node = begin;
 
       for(int i = 0 ; i <= index; i++)
       {
           if (i != index)
                node = node->next;}
           
	       return node->value;
       
 
   }
        void print();
        void pop();
      void erase(int index);
        void insert(int index, T a);
        private:
                Node<T>* begin;
                int size;
};
template <class T>
void List<T>::push(T a){
        Node<T>* node = new Node<T>;
        node->value = a;
        node->next=nullptr;
        Node<T>* end = begin;
        while(end && end->next){
                end=end->next;
        }
        size++;
        if(!end){
                begin=node;
        }
        else{
                end->next=node;
        }
}
template <class T>
void List<T>::print(){
        if(size<=1){
        return;
        }
        Node<T>* node=begin;
        while(node && node->next){
                std::cout<<node->value<<std::endl;
                node=node->next;
        }
        std::cout<<node->value<<std::endl;

}
template <class T>

void List<T>::pop(){
        if(size==0){
                return;
        }
        else if(size==1){
               Node<T>* node=begin;
               delete node;
                begin=nullptr;
                return;
        }
        else{
        Node<T>* node=begin;
        for(int i=1; i<size-1; i++){
                node=node->next;
        }
        Node<T>* end = node->next;
        delete end;
        node->next = nullptr;
        }
        --size;
}

template <class T>
void List<T>::erase(int index){
        Node<T>* node=begin;
        if(index==0){
        begin=node->next;
        delete node;
        return;
        }
        for(int i=1; i<index; i++){
                node = node->next;
        }
        Node<T>* end = node->next;
        Node<T>* end2 = end->next;
        //delete end;
        delete end;
                node->next = end2;
}

template <class T>
void List<T>::insert(int index, T a){
        Node<T>* node = new Node<T>;
        node->value = a;
        node->next = nullptr;
Node<T>* node1=begin;
        for(int i=1; i<index; i++){
               node1  = node1->next;
        }
        node->next = node1->next;
        node1->next = node;
        ++size;
}
