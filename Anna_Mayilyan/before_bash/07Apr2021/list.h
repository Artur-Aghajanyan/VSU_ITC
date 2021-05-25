#include <iostream>
template <class T>
 struct Node{
        Node* next;
		Node* prev;
        T value;
};
template <class T>
 class List{
        public:
                List(){
                        begin=nullptr;
                       	size=0;
						end = nullptr;
                }
		void push(T a);
        void print();
        void pop();
      	void erase(int index);
        void insert(int index, T a);
		int Size();
        private:
                Node<T>* begin;
				Node<T>* end;
                int size;
};
template <class T>
void List<T>::push(T a){
        Node<T>* node = new Node<T>;
        node->value = a;
        node->next=nullptr;
        node->prev = nullptr;
		Node<T>* n  = begin;
		while(n && n->next){
                n=n->next;
        }
        size++;
        
        if(!n){
                begin=node;
				
        }
        else{
               node -> prev = n;
			 n -> next = node;
			end = node;
        }
}
template <class T>
void List<T>::print(){
        Node<T>* node=begin;
        while(node && node->next){
                std::cout<<node->value<<std::endl;
                node=node->next;
        }
        std::cout<<node->value<<std::endl;
}

template <class T>
void List<T>::pop(){
        
        Node<T>* node=begin;
        for(int i=1; i<size; i++){
                node=node->next;
        }
        Node<T>* end = node -> prev;
		delete end;
		end = node;
		end -> next = nullptr;
		
        --size;
}

template <class T>
void List<T>::erase(int index){
        Node<T>* node=begin;
        if(index==0){
        begin  = node->next;
        delete node;
        return;
        }
        for(int i=1; i<index; i++){
                node = node->next;
        }
        Node<T>* e = node->next;
        Node<T>* e1 = e->next;
        delete end;
                node->next = e1;
				node-> prev = node;
				--size;
}

template <class T>
void List<T>::insert(int index, T a){
        Node<T>* node = new Node<T>;
        node->value = a;
		Node<T>* node1=begin;
		if(index == 0)
		{
			begin = node;
			node -> next = node1;
		}
        for(int i=0; i<index-1; ++i){
               node1  = node1->next;
        }
        Node<T>* n =  node1->next;
		node -> prev = node1;
		node->next = node1->next;
		n -> prev  = node;
		node1 -> next = node;
		
		++size;
} 
template <class T>
int List<T>::Size(){
	return size;
}
