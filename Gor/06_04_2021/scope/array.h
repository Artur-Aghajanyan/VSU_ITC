#include <iostream>
#include <cstring>

using namespace std;

class Array
{
	int* data;
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
		void push(int a)
		{
			int* newdata = new int [size+1];
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
			int* newdata = new int [size - 1];
			if(data)
                        {
                               //memcpy(newdata,data,(size-1)*4);
			       copy(data,data+size-1,newdata);
                        }
                        --size;
                        delete[] data;
                        data = newdata;
		};
		int top()
		{
			return data[size-1];
		}
		~Array()
		{
			delete[] data;
		};
};
