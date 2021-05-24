#include <iostream>

template<class T>
struct Node{
	Node<T>* next;
	T value;
};
template<class T>
class List{
	private:
		Node<T>* begin;
		int size;
	public:
		List(){
		Node<T>* begin = nullptr;
		int size = 0;
		}
		void push(T a);
		void print();
};

template<class T>
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
		}
		else{
			end->next = node;
		}
}
template<class T>
void List<T>::print(){
	Node<T>* node = begin;
	while(node && node->next){
		std::cout <<node->value <<std::endl;
		node = node->next;
	}
	if(node){
		std::cout <<node->value <<std::endl;
	}
}
