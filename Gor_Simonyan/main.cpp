#include <iostream>
#include "func.h"
using namespace std;

int main()
{
	int n,k;
	
	cout<<"Enter number for checking fibonachi - ";
	cin>>n;
	cout<<"Fibonachi number - "<<fib(n)<<endl;
	
	cout<<"Enter number ! - ";
	cin>>k;
	cout<<k<<"! = "<<fac(k)<<endl;;	
	
	int q;
	cout<<"Enter how long are your array - ";
	cin>>q;
	cout<<mij(q)<<endl;

	return 0;
}
