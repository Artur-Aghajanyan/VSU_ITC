#include <iostream>
#include <string>


template<class T>
struct Node
{
    T value;
    Node<T>* next;
};

template<class T>
class List
{
    private:
        Node<T>* begin;
    int size;
    public:
    List(){
        begin = nullptr;
        size = 0;
    }
    void push(T a);
    void print();
    void pop();
    void erase(int index);
    void insert(int index, T a);
    void getelem(int index);
    void operator [] (int index);  
};

template<class T>
void List<T>::push(T a)
{
   Node<T>* node = new Node<T>();
   node->value = a;
   node->next = nullptr;

   Node<T>* end = begin;
   while (end && end->next)
   {
        end = end->next;
   }
   size++;
   if(!end)
   {
      begin = node;
      return;
   }
   end->next = node;
}

template<class T>
void List<T>::print()
{
   Node<T>* end = begin;
    while(end && end->next)
   {
        std::cout << end->value << " ";
        end = end->next;
   }
    std::cout << std::endl;
}

template<class T>
void List<T>::pop()
{
    Node<T>* node = begin;
    if(size == 0) return;
    if(size == 1){
       delete begin;
       return;}

    for(int i = 1; i < size -1; i++)
    {
       node = node->next;
    }
    Node<T>* end = node->next;
    delete end;
    node->next = nullptr;
    --size;
}


template<class T>
void List<T>::erase(int index)
{
     Node<T>* node = begin;
    if(size == 0) return;
    if(size == index+ 1){
        pop();
       return;}
    if(size <= index) return;

    for(int i = 1; i < index;++i)
    {
       node = node->next;
    }

    Node<T>* end = node->next;
    node->next = end->next;
    delete end;
    --size;
}

template<class T>
void List<T>::insert(int index, T a)
{
     Node<T>* node = begin;
    if(size == 0) return;
    if(size == index+ 1){
         push(a);
       return;}
    if(size <= index) return;

    for(int i = 1; i < index;++i)
    {
       node = node->next;
    }
    Node<T>* node1  = new Node<T>;
    node1->value = a;
    node1->next = node->next;
    node->next = node1;
    ++size;
}

template<class T>
void List<T>::operator [] (int index)
{
    if(size <= index) return;
    Node<T>* end = begin;
    for(int i = 1; i <= index; ++i)
    {
        end = end -> next;
    }
    std::cout << end -> value << std::endl;
}

