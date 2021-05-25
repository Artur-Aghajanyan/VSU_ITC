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
		Array(int a)
		{
			size = a;
			T* data = new T [size];
		}
		Array(int a,int b)
		{
			size = a;
			T* data = new T [size];
			for(int i = 0; i < size;i++)
			{
				data[i] = b;
			}
		}
		Array(const Array &a1)
		{
			size = a1.size;
			copy(a1.data,a1.data+size,data);
		}
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
				copy(data,data+size,newdata);
			}
			++size;
			delete[] data;
			data = newdata;
			data[size-1] = a;
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
			       copy(data,data+size-1,newdata);
                        }
                        --size;
			cout<<"Deleted - '"<<data[size]<<"'"<<endl;
                        delete[] data;
                        data = newdata;
		};
		void erase(int index)
		{
			T* newdata = new T [size-1];
			if(data)
                        {
                                //memcpy(newdata,data,index*4);
				//memcpy(newdata + index,data+index+1,(size-index)*4);
				copy(data,data+index,newdata);
				copy(data+index+1,data+size,newdata+index);
			}
                        --size;
                        delete[] data;
                        data = newdata;
               	};
		void empty()
		{
			bool t = false;
			if(data)
			{
				t = true;
			}
			if(t)
			{
				cout<<"Not empty!"<<endl;
			}
			else
			{
				cout<<"Empty!"<<endl;
			}
		};
		void insert(int a,int b)
		{
			T* newdata = new T [size+1];
                        if(data)
                        {
                                //memcpy(data,newdata,size*4);
                                copy(data,data+a,newdata);
				newdata[a] = b;
				copy(data+a,data+size,newdata+a+1);
                        }
                        ++size;
                        delete[] data;
                        data = newdata;
                        data[size-1] = a;
		}
		int &operator[](int i)
		{
			if(i > size-1)
			{
				cout<<"Out of range!"<<endl;
				return size;
			}
			return data[i];
		}
		~Array()
		{
			delete[] data;
		};
};
