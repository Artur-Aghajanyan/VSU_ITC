template <class T>
struct Node {
	Node<T>* next;
	Node<T>* previous;
	T value;
};

template <class T>
class List {
	private:
		Node<T>* begin;
		Node<T>* end;
		int size;
	
	public:
		List();
		void push(T val);
		void pop();
		void erase(int index);
		void insert(int index, T val);
		void print();
		T top();
		int Size();
};

template <class T>
List<T> :: List() {
	begin = nullptr;
	end = nullptr;
	size = 0;
}

template <class T>
void List<T> :: push(T val) {
	Node<T>* node = new Node<T>;
	node -> value = val;
	node -> next = nullptr;
	node -> previous = nullptr;
	Node<T>* newnode = begin;
	
	while(newnode && newnode -> next) {
		newnode = newnode -> next;
	}
	++size;
	
	if(!newnode) {
		begin = node;
		return;
	}
	node -> previous = newnode;
	newnode -> next = node;
	end = node;
}

template <class T>
void List<T> :: pop() {
/*	Node<T>* node = begin;
	for(int i = 1; i < size - 1; ++i) {
		node = node -> next;
	}
	
	Node<T>* newnode = node -> next;
	delete newnode;
	node -> next = nullptr;
	--size;*/
	Node<T>* node = end -> previous;
	delete end;
	node -> next = nullptr;
	--size;
}

template <class T>
	void List<T> :: erase(int index) {
      Node<T>* node = begin;
      for(int i = 1; i < index; ++i) {
          node = node -> next;
     }
      Node<T>* knode = node -> next;
      Node<T>* newnode = knode -> next;
      delete knode;
      node -> next = newnode;
      newnode -> previous = node;
      --size;
}

template <class T>
void List<T> :: insert(int index, T val) {
	Node<T>* node = new Node<T>;
	node -> value = val;
	Node<T>* newnode = begin;
	if(index == 0) {
		node -> next = begin;
		node -> previous = nullptr;
		begin = node;
	} else {
		for(int i = 0; i < index - 1; ++i) {
			newnode = newnode -> next;
		}
	
		Node<T>* knode = newnode -> next;
		node -> previous = newnode;
		node -> next = newnode -> next;
		knode -> previous = node;
		newnode -> next = node;
    }
	++size;
}

template <class T>
void List<T> :: print() {
	Node<T>* node = begin;
	for(int i = 0; i < size; ++i) {
		std :: cout << node -> value << std :: endl;
		node = node -> next;
	}
}

template <class T>
T List<T> :: top() {
	Node<T>* node = begin;
	for(int i = 1; i < size; ++i) {
		node = node -> next;
	}
	return node -> value;
}

template <class T>
int List<T> :: Size() {
	return size;
}
