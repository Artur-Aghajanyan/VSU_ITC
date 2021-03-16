template<class T>
struct Node
{
    Node<T>* next;
    T value;
};

template<class T>
class List
{
private:
    Node<T>* begin;
    int size;
public:
    List();
    void push(T a);
    void print();
    void pop();
    void insert(int index, T a);
    void ibase(int index);
    T& operator[](int);
};

template<class T>
List<T>::List()
{
    begin = nullptr;
    size = 0;
}

template<class T>
void List<T> :: push(T a) {
    ++size;
    Node<T>* node = new Node<T>;
    node->value = a;
    node->next = nullptr;
    Node<T>* end = begin;
    while(end && end->next) {
        end = end -> next;
    }
    if(!end) {
        begin = node;
        return;
    }
    end -> next = node;
}
template<class T>
void List<T> :: print() {
    Node<T> * tmp = begin;
    for (int i = 0; i < size; i++)
    {
        std :: cout << tmp -> value;
        tmp = tmp -> next;
    }
    
}

template<class T>
void List<T> :: pop() {
    Node<T>* tmp = begin;
    if (size == 0)
    {
        return;
    }
    
    for (int i = 0; i < size-1; i++)
    {
        tmp = tmp -> next;
    }
    delete tmp->next;
    tmp -> next = nullptr;
    --size;
}

template<class T>
void List<T> :: insert(int index, T a) {
    ++size;
    Node<T>* node = new Node<T>;
    node->value = a;
    node->next = nullptr;
    if(index == 0) {
        node -> next = begin;
        begin = node;
        return;
    }
    Node<T>* end = begin;
    for (int i = 0; i < index - 1; i++)
    {
        end = end -> next;
    }
    Node<T> * tmp = end -> next;
    node -> next = end -> next;
    end -> next = node;
}

template<class T>
void List<T> :: ibase(int index) {
    Node<T>* end = begin;
    for (int i = 0; i < index -1; i++)     
    {
        end = end -> next;
    }
    Node<T> * tmp = end -> next;
    end ->next = tmp -> next;
    --size;
    delete tmp;
}
template<class T>
T& List<T> :: operator[](int index){
    Node<T>* tmp = begin;
    for(int i = 0; i < index; ++i) {
        tmp = tmp -> next;
    }
    return tmp -> value;
} 