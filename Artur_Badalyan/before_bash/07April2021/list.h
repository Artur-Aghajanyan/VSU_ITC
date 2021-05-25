#include <iostream>

template <class T>
struct Node{
	T value;
	Node<T>* next;
	Node<T>* tail;
};


template <class T>
class List{

	private:
	int size;
	Node<T>* head;
	Node<T>* last;

	public:
	List();
	void push(T value);
	void pop();
	void printList();
	void erase(int index);
	void insert(int index,T value);
};

template<class T>
List<T>::List(){
	head = nullptr;
	last = nullptr;
	size = 0;	
}


template <class T>
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
	node->tail = curr;
	last = node;
	}

	++size;
}

template <class T>
void List<T>::pop() {
	Node<T>* curr = head;	
	if(size == 0){
		return;
	}else if(size == 1){
		delete curr;
		head = nullptr;
		--size;
		return;
	}
	
	Node<T>* end = last->tail;
	end->next = nullptr;
	delete last;
	last = end;
	--size;	
}

template <class T>
void List<T>::erase(int index) {
	Node<T>* node = head;
	if (index == 0){
		Node<T>* temp = node->next;
		delete node;
		temp->tail = nullptr;
		head = temp;
		--size;
	}else{
	for (int i = 1;i < index-1;++i) {
		node = node->next;
	}
	--size;
	Node<T>* temp = node->next;
  	node->next = temp->next;
	temp->tail = node;
	delete temp;
	}	
}

template <class T>
void List<T>::insert(int index,T value) {
	Node<T>* node = head;
	Node<T>* newnode = new Node<T>();
	newnode->value = value;
	for(int i = 0;i < index-1;++i){
		node = node->next;
	}
	
	Node<T>* temp = node->next;
	newnode->next = temp;
	temp->tail = newnode;
	
	node->next = newnode;
	newnode->tail = node;
	
	++size;
}

template <class T>
void List<T>::printList() {
	Node<T>* node = head;
	for(int i = 0; i < size;++i) {	
		std::cout <<"Value of Node N"<< i <<" = " << node->value <<std::endl;
		node = node->next;
	}
}

