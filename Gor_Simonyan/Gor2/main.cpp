#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	ITC::String str("Hello");
	cout<<"Object print - "<<str<<endl;
	cout<<"Function print - ";
	str.print();
	return 0;
}
