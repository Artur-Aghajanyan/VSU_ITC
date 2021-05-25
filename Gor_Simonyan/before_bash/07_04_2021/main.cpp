#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	string t;
	while(true)
	{
	cout<<"Select variable(int,string) - ";
	cin>>t;
	if(t == "int")
	{
	cout<<"For end write 0!"<<endl;
	List<int> l;
	int s;
	int r = 0;
	while(true)
	{
		cout<<"List["<<r<<"] - ";
		cin>>s;
		r++;
		if(s == 0)
		{
			break;
		}
		else
		{
			l.push(s);
		}
	}
	cout<<"__________print____________"<<endl;
        l.print();
        cout<<"__________pop______________"<<endl;
        l.pop();
        l.print();
        cout<<"__________erase____________"<<endl;
        int a;
        cout<<"Input index - ";
        cin>>a;
        if(l.erase(a))
        {
                l.print();
        }
        cout<<"__________insert___________"<<endl;
        int b,c;
        cout<<"Input index - ";
        cin>>b;
        cout<<"Input number - ";
        cin>>c;
        if(l.insert(b,c))
        {
                l.print();
        }
	cout<<"__________List[]___________"<<endl;
	int h;
	cout<<"Input index - ";
	cin>>h;
        cout<<l[h]<<endl;
	break;
	}

	else if(t == "string")
	{
	cout<<"For end write end!"<<endl;
	List<string> l;
        string s;
        int r = 0;
        while(true)
        {
                cout<<"List["<<r<<"] - ";
                cin>>s;
                r++;
                if(s == "end")
                {
                        break;
                }
                else
                {
                        l.push(s);
                }
       	}
	cout<<"__________print____________"<<endl;
        l.print();
        cout<<"__________pop______________"<<endl;
        l.pop();
        l.print();
        cout<<"__________erase____________"<<endl;
        int a;
        cout<<"Input index - ";
        cin>>a;
        if(l.erase(a))
        {
                l.print();
        }
        cout<<"__________insert___________"<<endl;
        int b;
	string c;
        cout<<"Input index - ";
        cin>>b;
        cout<<"Input number - ";
        cin>>c;
        if(l.insert(b,c))
        {
                l.print();
        }
	cout<<"__________List[]___________"<<endl;
        int h;
        cout<<"Input index - ";
        cin>>h;
        cout<<l[h]<<endl;
	break;
	}

	else
	{
		cout<<"pls write int or string!"<<endl;
	}
	}
	return 0;
}
