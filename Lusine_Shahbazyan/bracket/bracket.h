class Stack
{
public:
    Stack(int n);
    Stack(Stack& st);
    ~Stack();
    bool empty();
    char top();
    void push(char obj);
    void pop();
private:
    char stack_size;
    char array_capacity;
    char *array;
};

Stack::Stack(int n)
{
	stack_size = 0;
	array_capacity = n;
	array = new char[array_capacity];
}

Stack::Stack(Stack& st)
{
    stack_size = st.stack_size;
    array_capacity = st.array_capacity;
    array = new char[array_capacity];
    for(int i = 0; i < stack_size; i++) 
    {
        array[i] = st.array[i];
    }
}

Stack::~Stack() {
    delete [] array;
}

bool Stack::empty()
{
    if(stack_size == 0) return true;
    else return false;
}
char Stack::top()
{
    if (!empty())
    {
        return array[stack_size - 1];
    }
}

void Stack::push(char obj) 
{
    array[stack_size] = obj;
    ++stack_size;
}

void Stack::pop()
{
    if (empty()) return;
    --stack_size;
}
