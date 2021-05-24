#include <iostream>
#include "array.h"

using namespace std;

int main()
{
	string q;
	while(true)
	{
	cout<<"Select variable(int,string) - ";
	cin>>q;
	if(q == "int")
	{
	cout<<"for end write 0"<<endl;
	Array<int> a;
	int s;
	int r = 0;
	while (true)
	{
		cout<<"array["<<r<<"] - ";
		cin>>s;
		r++;
		if(s == 0)
		{
			break;
		}
		else
		{
			a.push(s);
		}
	}
	a.print();
        a.pop();
        a.print();
	a.empty();
	int k,l;
	cout<<"Select index of insert number - ";
	cin>>k;
	cout<<"Sellect number for inserting - ";
	cin>>l;
	a.insert(k,l);
	a.print();
	cout<<a[1]<<endl;
	break;
	}
	else if(q == "string")
        {
        cout<<"for end write end"<<endl;
        Array<string> a;
        string s;
        int r = 0;
        while (true)
        {
                cout<<"array["<<r<<"] - ";
                cin>>s;
                r++;
                if(s == "end")
                {
                        break;
                }
                else
                {
                        a.push(s);
                }
	}
	a.print();
        a.pop();
        a.print();
	break;
	}
	else
        {
                cout<<"Pls write int or string"<<endl;
        }
	}
	return 0;
}
