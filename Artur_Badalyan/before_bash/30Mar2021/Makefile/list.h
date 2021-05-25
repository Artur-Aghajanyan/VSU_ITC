#include <iostream>

template<class T>
struct Node{
	T value;
	Node<T>* next;
};


template<class T>
class List{

	private:
	int size;
	Node<T>* head;

	public:
	List();
	void push(T a);
	void pop();
	void printList();
	void erase(int index);
	void insert(int index,T a);
    T operator[](int index);
};


template<class T>
List<T>::List(){
	head = nullptr;
	size = 0;	
}

template <class T>
T List<T>::operator[](int index){
	if(index < 0 || index > size){
		return "Error!";
	}
    Node<T>* curr = head;
	for(int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->value;
}


template<class T>
void List<T>::erase(int index){
	if (size < index){
		return;
	}	
	Node<T>* node = head;
	for(int i = 1;i < index;i++){
		node = node->next;
	}
	--size;
	Node<T>* end = node->next;
	node->next = end->next;
	delete end;
}

template<class T>
void List<T>::insert(int index,T a){
	Node<T>* node = head;
	Node<T>* newnode = new Node<T>();
	newnode->value = a;
	
	for(int i = 1;i < index;i++){
		node = node->next;
	}
	++size;
	newnode->next = node->next;
	node->next = newnode;
}



template<class T>
void List<T>::push(T a){
	Node<T>* node = new Node<T>();
	node->value = a;
	node->next = nullptr;		
	Node<T>* curr = head;
	while (curr && curr->next){
		curr = curr->next;
	}

	if(!curr){
		head=node;
	}else{
	curr->next = node;
	}

	++size;

}

template<class T>
void List<T>::pop(){
	Node<T>* curr = head;

	if(size==0){
        return;
    } else if(size == 1){
        delete curr;
        head = nullptr;
        --size;
        return;
   }

	for(int i = 1;i < size-1;i++){
		curr = curr->next;
	}
	Node<T>* temp = curr->next;
	delete temp;
	curr->next = nullptr;
	--size;

}

template<class T>
void List<T>::printList(){
	Node<T>* node = head;	
	for(int i = 0;i < size;i++){
		std::cout << node->value <<std::endl;
		node = node->next;
	}		

}
