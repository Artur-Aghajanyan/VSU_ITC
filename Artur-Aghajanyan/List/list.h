#include <iostream>

template <class T>
struct Node{
	T value;
	Node* next;
	Node* prev;
};

template <class T>
class List{
	private:
		Node<T>* head;
		Node<T>* bottom;
		int size;
	public:
		List();
		void pop();
		void print();
		void push(T value);
		void erase(int index);
		void insert(int index, T value);
};

template <class T>
List<T>::List() {
	this->head = nullptr;
	this->bottom = nullptr;
	this->size = 0;
}

template <class T>
void List<T>::push(T value) {
	Node<T>* node = new Node<T>;
	node->next = nullptr;
	node->value = value;
	Node<T>* last = head;
	while(last && last->next) {
		last = last->next;
	}

	if(!last) {
		this->head = node;
		node->prev = nullptr;
	}
	else {
		this->bottom = node;
		last->next = node;
		node->prev = last;
	}
	this->size++;
}

template <class T>
void List<T>::print() {
	Node<T>* node = head;
	for(int i = 0; i < this->size; ++i){
		std::cout << node->value << " - Node<T>_value\n";
		node = node->next;
	}
}

template <class T>
void List<T>::pop() {
	Node<T>* last = this->bottom->prev;
	delete bottom;
	bottom = last;
	last->next = nullptr;
	--this->size;
}

template <class T>
void List<T>::erase(int index) {
	if(size/2 > index){
		Node<T>* node = head;
	
		if(index == 0) {
			Node<T>* last = node->next;
			delete node;
			last->prev = nullptr;
			head = last;
		}
		else{
			for(int i = 1; i < index; ++i){
				node = node->next;
			}

			Node<T>* last = node->next;
			node->next = last->next;
			last->prev = node;
			delete last;
		}
	}else {
		Node<T>* node = bottom;
		for(int j = size; j > index; --j){
			node = node->prev;
		}	
		Node<T>* last = node->next;
		node->next = last->next;
		last->prev = node;
	}

	--this->size;
}

template <class T>
void List<T>::insert(int index, T value) { 
	if(this->size < index) return;
	
	Node<T>* temp = new Node<T>;
	temp->value = value;
	
	if(this->size/2 > index){
		Node<T>* node = head;
		
		for(int i = 0; i < index-1; ++i){
			node = node->next;
		}	

		temp->next = node->next;
		node->next->prev = temp;
		node->next = temp;
		temp->prev = node;
	}else {
		Node<T>* node = bottom;
		
		for(int i = size; i > index; --i){
			node = node->prev;
		}

		temp->next = node->next;
		node->next->prev = temp;
		node->next = temp;
		temp->prev = node;
	}

}
