#include <iostream>
template <class T>
struct Node{
	Node<T>* next;
	T value;
};
template <class T>
class List{
	private:
	Node<T>* begin;
	int size;
	public:
	List();
	T operator[](int pos);
	void erase(int i);
	void pop();
	void print();
	void push(T a);
	void insert(int i, T value);
};
template <class T>
List<T>::List(){
	this->begin = nullptr;
	this->size = 0;
}
template <class T>
T List<T>::operator[](int index){
	if(index < 0 || index > size){
		return "Ther is not value!!";
	}
    Node<T>* current = begin;
	for(int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->value;
}

template <class T>
void List<T>::push(T a){	
	Node<T>* node = new Node<T>;
	node->value = a;
	node->next = nullptr;
	Node<T>* end = begin;
	while(end && end->next){
		end = end->next;
	}

	size++;
	if(!end){
		begin = node;
	}else{
		end->next = node;
	}
}

template <class T>
void List<T>::pop(){
	Node<T>* node = begin;
	for(int i = 1; i < size-1; i++){
		node = node->next;
	}
	Node<T>* end = node->next;
	delete end;
	node->next = nullptr;
	--size;
}

template <class T>
void List<T>::insert(int index, T value){
	if(size < index){
		return;
	}
	Node<T>* node = begin;

	Node<T>* node1 = new Node<T>;
	node1->value = value;
	node1->next = nullptr;
	for(int i = 0; i < index-1; i++){
		node = node->next;
	}
	++size;
	node1->next = node->next;
	node->next = node1;

}

template <class T>
void List<T>::erase(int index){
	Node<T>* node = begin;
	for(int i = 1; i < index; i++){
		node = node->next;
	}
	--size;
	Node<T>* end = node->next;

	node->next = end->next;
	delete end;
}

template <class T>
void List<T>::print(){
	Node<T>* node = begin;
	for(int i = 0; i < size; i++){
		std::cout<<node->value<<std::endl;
		node = node->next;
	}
}
