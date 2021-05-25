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
		~Array()
		{
			delete[] data;
		};
};
