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
        int g;
        while(true)
        {
                cout<<"Select index for deleteing - ";
                cin>>g;
                if(g>a.get_size()-1)
                {
                        cout<<"Out of range"<<endl;
                }
                else
                {
                        break;
                }
        }
        a.erase(g);
        a.print();
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
        int g;
        while(true)
        {
                cout<<"Select index for deleteing - ";
                cin>>g;
                if(g>a.get_size()-1)
                {
                        cout<<"Out of range"<<endl;
                }
                else
                {
                        break;
                }
        }
        a.erase(g);
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
