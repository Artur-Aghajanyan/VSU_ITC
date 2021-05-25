using namespace std;

template<class T>
struct Node
{
	Node* next;
	T value;
};

template<class T>
class List
{
	Node<T>* begin;
	int size;
	public:
		List()
		{
			begin = nullptr;
			size = 0;
		};

		void push(T a)
		{
			Node<T>* node = new Node<T>;
			node->value = a;
			node->next = nullptr;
			Node<T>* end = begin;
			while(end && end->next)
			{
				end = end->next;
			}
			size++;
			if(!end)
			{
				begin = node;
			}
			else
			{
				end->next = node;
			}
		};

		void print()
		{
			Node<T>* node = begin;
			while(node && node->next)
			{
				cout<<node->value<<endl;
				node = node->next;
			}
			if(node)
			{
				cout<<node->value<<endl;
			}
		};

		void pop()
		{
			Node<T>* node = begin;
			if(size == 0)
			{
				return;
			}
			else if(size == 1)
			{
				delete begin;
			}
			else
			{
				for(int i = 1;i<size-1;i++)
				{
					node = node->next;
				}
			Node<T>* end = node->next;
			delete end;
			node->next = nullptr;
			}
			--size;
		};

		bool erase(int index)
		{
			Node<T>* node = begin;
			if(index == 0)
			{
				Node<T>* next = node->next;
				delete node;
				begin = next;
				return true;
			}
			else if(index > size-1)
			{
				cout<<"Out of range!"<<endl;
				return false;
			}
			else
			{
				for(int i = 1;i<index;i++)
				{
					node = node->next;
				}
				--size;
				Node<T>* end = node->next;
				Node<T>* next = end->next;
				delete end;
				node->next = next;
				return true;
			}
		};

		bool insert(int index, T value)
		{
			Node<T>* node = begin;
			Node<T>* newnode = new Node<T>;
			newnode->value = value;
			newnode->next = nullptr;
			if(index == 0)
			{
				newnode->next = node;
				begin = newnode;
				return true;
			}
			else if(index>size)
			{
				cout<<"Out of rnage!"<<endl;
				return false;
			}
			else
			{
				for(int i = 1;i<index;i++)
				{
					node = node->next;
				}
				++size;
				newnode->next = node->next;
				node->next = newnode;
				return true;
			}
		};
	T &operator[](int i)
	{
		Node<T>* node = begin;
		Node<T>* newnode = new Node<T>;
		newnode->next = nullptr;
		if(i == 0)
		{
			newnode->value = begin->value;
		}
		else if(i>size-1)
		{
			cout<<"Out of rnage!"<<endl;
		}
		else
		{
			for(int a = 1;a<i+1;a++)
			{
				node = node->next;
			}
			newnode->value = node->value;
		}
		return newnode->value;
	};
};
