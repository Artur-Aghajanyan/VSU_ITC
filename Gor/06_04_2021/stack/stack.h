#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class Array
{
	T* data;
	int size;
	public:
		Array()
		{
			size = 0;
			data = nullptr;
		};
		int get_size()
		{
			return size;
		};
		void push(T a)
		{
			T* newdata = new T [size+1];
			if(data)
			{
				//memcpy(data,newdata,size*4);
				copy(data,data+size,newdata+1);
			}
			++size;
			delete[] data;
			data = newdata;
			data[0] = a;
		};
		void print()
		{
			for(int i =0;i<size;i++)
			{
				if(i==0)
				{
					cout<<"["<<data[i]<<",";
				}
				else if(i==size-1)
				{
					cout<<data[size-1]<<"]"<<endl;
				}
				else
				{
					cout<<data[i]<<",";
				}
			}
		};
		void pop()
		{
			T* newdata = new T [size - 1];
			if(data)
                        {
                               //memcpy(newdata,data,(size-1)*4);
			       copy(data+1,data+size,newdata);
                        }
                        --size;
			cout<<"Deleted - '"<<data[0]<<"'"<<endl;
                        delete[] data;
                        data = newdata;
		};
		void empty()
		{
			if(size == 0 )
			{
				cout<<"Empty!"<<endl;
			}
			else
			{
				cout<<"Not Empty!"<<endl;
			}
		}
		void top()
		{
			return data[0];
		}
		~Array()
		{
			delete[] data;
		};
};

