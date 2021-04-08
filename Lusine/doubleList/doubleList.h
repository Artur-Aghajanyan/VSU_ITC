template<class T>
struct Node
{   
    T value;
    Node<T>* next;
    Node<T>* prev;
};

template<class T>
class List
{
private:
    Node<T>* head;
    Node<T>* tail;
	int size;
public:
   List()
   {
	head = nullptr;
        tail = nullptr;
	size = 0;
    }
    void push(T element);
    void print();
    void pop();
    void erase(int index);
    void insert(int index, T element);
};


template<class T>
void List<T>::push(T element)
{
    Node<T>* node = new Node<T>();
    node->value = element;
    node -> next = nullptr;
    if(size == 0)
    {
        head = node;
        ++size;
        return;        
    }
    else if (size == 1)
    {
        ++size;
        head -> next = tail;
        tail = node;
        tail -> prev = head;
        return;
    } else {
        Node<T>* end = head;
        while (end && end->next)
        {
            end = end->next;
        }
        ++size;
        end -> next = tail;
        tail = node;
        tail -> prev = end;
    }
}

template<class T>
void List<T>::print()
{
    Node<T>* end = head;
    while(end)
    {
         std::cout << end->value << " ";
         end = end->next;
    }
    std::cout << std::endl;
}

template<class T>
void List<T>::pop()
{
    if(size == 0)  return;
    if(size == 1)
    {
         delete head;
         --size;
         return;
    }
    
    Node<T>* node = tail -> prev;
    delete tail;
    tail = node;
    tail -> next = nullptr;
    --size;
    
}

template<class T>
void List<T>::erase(int index)
{
    if(size <= index) return;
    if(size == 0) return;
    if(index == 0)
    {
         head = head -> next;
         head -> prev = nullptr;
         return;
    }

    if(size == index + 1)
    {
         pop();
         return;
    }
    
    Node<T>* node = head;
    for(int i = 1; i < index; ++i)
    {
         node = node->next;
         node -> next -> prev = node;
    }
    
    node -> next = node -> next -> next;
    node -> next -> prev = node;
    --size;
}

template<class T>
void List<T>::insert(int index, T element)
{
    if(size <= index) return;
    if(size == 0) return;
    if(size == index + 1) 
    {
         push(element);
         return;
    }
    Node<T>* temp = head;
    Node<T>* node  = new Node<T>;
    node -> value = element;
    for(int i = 1; i < index; ++i)
    {
        temp = temp -> next;
        temp -> next -> prev = temp;
    }
    node -> next = temp -> next;
    temp -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
    ++size;
}

