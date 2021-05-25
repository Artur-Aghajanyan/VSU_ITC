#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
	Complex a;
	Complex b;
	Complex c;
	cout<<"Enter first complex number(example` 5+7i) - ";
	cin>>a;
	cout<<"Enter second complex number(example 1+5i) - ";
	cin>>b;
	char oper;
	cout<<"Enter operator(+,-,*) - ";
	cin>>oper;
	if(oper == '+')
	{
		c = a + b;
	}	
	else if(oper == '-')
	{
		c = a - b;
	}
	else if(oper == '*')
	{
		c = a * b;
	}
	else
	{
		cout<<"error"<<endl;
	}
	cout<<"Complex answer - "<<c<<endl;
}
