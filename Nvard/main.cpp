#include <iostream>
using namespace std;

class Person
{
	int age;
	int* data = new int[10];
	public:
	Person(int k)
	{
		age = k;
		for(int i = 0;i<10;i++)
		{
			data[i] = i;
		}
	}

	Person(const Person& ob1)
	{
		age = ob1.age;
		data = new int[10];
		for(int i = 0;i<10;i++)
		{
			data[i] = ob1.data[i];
		}
	}

};

int main()
{	
	Person ob1(5);
	Person ob2 = ob1;
	return 0;
}
