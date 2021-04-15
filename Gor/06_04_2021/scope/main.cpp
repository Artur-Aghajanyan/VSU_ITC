#include <iostream>
#include <cstring>
#include "array.h"

using namespace std;

int main()
{
	Array a;
	string s;
	cout<<"Enter the text - ";
	cin>>s;
	int k = 0,d = 0,u = 0;
	int ki,di,ui;
	for(int i = 0;i < s.length();i++)
	{
		switch(s[i])
		{
			case '[':
				++u;
				ui = i;
				a.push(1);
				break;
			case ']':
				--u;
				ui = i;
				{
				int t = a.top();
				if(t == 1)
				{
					a.pop();
				}
				else
				{
					--u;
				}
				}
				break;
			case '(':
				++k;
				ki = i;
				a.push(2);
				break;
			case ')':
				--k;
				ki = i;
				{
				int t = a.top();
                                if(t == 2)
                                {
                                        a.pop();
                                }
                                else
                                {
                                        --k;
                                }
				}
				break;
			case '{':
				++d;
				di = i;
				a.push(3);
				break;
			case '}':
				--d;
				di = i;
				{
				int t = a.top();
                                if(t == 3)
                                {
                                        a.pop();
                                }
                                else
                                {
                                        --d;
                                }
				}
				break;
		}
		if(u < 0)
		{
			cout<<"Error!"<<endl;
			cout<<ui<<endl;
			return 0;
		}
		else if(d < 0)
                {
                        cout<<"Error!"<<endl;
			cout<<di<<endl;
                        return 0;
                }
		else if(k < 0)
                {
                        cout<<"Error!"<<endl;
			cout<<ki<<endl;
                        return 0;
                }
	}
	if(u != 0)
        {
                cout<<"Error!"<<endl;
                cout<<ui<<endl;
		a.print();
	}
	if(d != 0)
        {
                cout<<"Error!"<<endl;
                cout<<di<<endl;
                a.print();
        }
	if(k != 0)
        {
                cout<<"Error!"<<endl;
                cout<<ki<<endl;
                a.print();
        }
	return 0;
}
