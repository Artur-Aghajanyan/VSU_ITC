template <class T>
class Stack {
	private:
		T* data;
		int size;
		
	public:
		Stack();
		~Stack();
	    bool empty();
		void pop();
		void push(const T& val);
		unsigned int Size();
		void swap(Stack& x);
		T top();
};

template <class T>
Stack <T> :: Stack() {
	data = nullptr;
	size = 0;
}

template <class T>
Stack <T> :: ~Stack() {
	delete [] data;
}

template <class T>
bool Stack <T> :: empty() {
	if(size == 0) {
		return true;
	} else {
		return false;
	}
}

template <class T>
void Stack <T> :: pop() {
	T* newdata = new T[size - 1];
	std :: copy(data, data + size - 1, newdata);
	--size;
	delete [] data;
	data = newdata;
}

template <class T>
void Stack <T> :: push(const T& val) {
	T* newdata = new T[size + 1];
	std :: copy(data, data + size, newdata);
	++size;
	newdata[size - 1] = val;
	delete [] data;
	data = newdata;
}

template <class T>
unsigned int Stack <T> :: Size() {
	return size;
}

template <class T>
void Stack <T> :: swap(Stack& x) {
	T* newdata = new T[size];
	int newsize;
	std :: copy (data, data + size, newdata);
	newsize = size;
	std :: copy (x.data, x.data + x.size, data);
	size = x.size;
	std :: copy (newdata, newdata + size, x.data);
	x.size = newsize;
} 

template <class T>
T Stack <T> :: top() {
	return data[size - 1];
}
