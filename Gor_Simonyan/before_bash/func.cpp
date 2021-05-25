#include <iostream>
using namespace std;

int fib(int n)
{
	int a,b,c;
	if(n == 1)
	{
		c = 0;
	}
	else if (n == 2)
	{
		c = 1;
	}
	else
	{
		a = 0;
		b = 1;
		int f = 3;
		while (f<=n)
		{
			c = a + b;
			a = b;
			b = c;
			f++;	
		}
	}
	return c;
}

int fac(int k)
{
	int fact = 1;
	for(int i = 1;i<=k;i++)
	{
		fact *=i;
	}
	return fact;
}

float mij(int q)
{

	int* arr = new int[q];
	float m = 0;
	for(int i = 0;i<q;i++)
	{
		cout<<"arr["<<i<<"] - ";
		cin>>arr[i];
		m += arr[i];
	}
	cout<<"Arithmetic average - ";
	return m/q;

}
