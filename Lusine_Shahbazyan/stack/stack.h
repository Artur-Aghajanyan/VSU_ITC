template <class T>
class Stack
{
private:
    unsigned size;
    unsigned capacity;
    T *stack;
public:    
    Stack();
    Stack(unsigned cap);
    void push(T element);
    unsigned getSize();
    bool empty();
    void pop();
    T top();
};

template <class T>
Stack<T>::Stack()
{
    size = 0;
    capacity = 0;
}

template <class T>
unsigned Stack<T>::getSize()
{
    return size;
}

template <class T>
bool Stack<T>::empty()
{
    if(size == 0) return true;
    else return false;
}

template <class T>
Stack<T>::Stack(unsigned cap)
{
    size = 0;
    capacity = cap;
    stack = new T[capacity];
}

template <class T>
void Stack<T>::pop()
{
    if(empty())
    {
        return;
    }
    else --size;   
}

template <class T>
void Stack<T>::push(T element)
{
    if(size == capacity)
    {
        return;
    }
    stack[size] = element;
    ++size;
}

template <class T>
T Stack<T>::top()
{
    if(size != 0)
    {
         return stack[size - 1];
    }
}


