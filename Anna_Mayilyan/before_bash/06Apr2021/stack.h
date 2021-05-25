template <class T>
class Stack{
private:
	T* data;
	int size;
public:
	Stack();
	void push( T elem);
	void pop();
	int Size();
	bool empty();
	void swap(Stack& s);
	int top();
	~Stack();
	};
template <class T>
Stack<T>::Stack()
{
	data = nullptr;
	size = 0;
}

template <class T>
void Stack<T>::push(T elem)
{
	T* newdata = new T[size];
	for(int i = 0; i < size; ++i)
	newdata[i] = data[i];
	delete [] newdata;
	data = newdata;
	++size;
}

template <class T>
void Stack<T>::pop()
{
	T* newdata = new T[size];
	if(size){
		for(int i = 0; i < size; ++i)
		newdata[i] = data[i];
		}
	delete [] data;
	data = newdata;
	--size;
}	

template <class T>
Stack<T>::~Stack()
{
	delete [] data;
}

template <class T>
bool Stack<T>::empty()
{
	if(size = 0)
 		return 0;
	else
		return 1;
}

template <class T>
int Stack<T>::Size()
{
return size;
}

template <class T>
int Stack<T>::top()
{
	return data[size-1];
}

template <class T>
void Stack<T>::swap(Stack& s)
{
	size = s.size;
	T* before = new T[size];
	for(int i = 0; i < size; ++i)
	before[i] = data[i];
	T* after = new T[size];
	for(int i = 0; i < size; ++i)
	after[i] = data[i];
	data = after;
	s.data = before;
}


