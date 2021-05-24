#include <iostream>
#include "complex.h"

using namespace std;

int main()
{	
	cout<<"Enter type (int,float) - ";
	string s;
	cin>>s;
	if(s == "int")
	{
	Complex<int> a;
	Complex<int> b;
	Complex<int> c;
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
	else if(s == "float")
	{
	Complex<float> a;
        Complex<float> b;
        Complex<float> c;
        cout<<"Enter first complex number(example` 5.2+7.6i) - ";
        cin>>a;
        cout<<"Enter second complex number(example 1.1+5.9i) - ";
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
	else
	{
		cout<<"error type"<<endl;
	}
}
