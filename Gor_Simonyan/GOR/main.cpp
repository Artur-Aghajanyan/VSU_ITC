#include <iostream>
using namespace std;

class Person
{
	int age;
	int* data = new int[10];
	public:
		Person(int a)
		{
			age = a;
			for(int i = 0;i<10;i++)
			{
				data[i] = i;
			}
		}

		Person(const Person& p1)
		{
			age = p1.age;
			data = new int[10];
			for(int i = 0;i<10;i++)
			{
				data[i] = p1.data[i];
			}

		}

};

int main()
{	
	Person p1(5);
	Person p2 = p1;
	return 0;
}
