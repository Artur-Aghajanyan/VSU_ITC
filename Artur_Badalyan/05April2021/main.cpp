#include <iostream>
#include "vector.h"
using namespace std;

int main(){

    Vector v;

	cout << "---------- push_back ----------"<<endl;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }


     for (int i = 0; i < v.vec_size(); i++)
    {
        cout << "element " << i << " = "<< v[i]<<endl;
    }
	
	cout << "---------- pop_back ----------"<<endl;

	 v.pop_back();

  	for (int i = 0; i < v.vec_size(); i++)
    {
        cout << "element " << i << " = "<< v[i]<<endl;
    }

	cout << "---------- insert ----------"<<endl;
	v.insert(5,105);
	
  	for (int i = 0; i < v.vec_size(); i++)
    {
        cout << "element " << i << " = "<< v[i]<<endl;
    }


	cout << "---------- size ----------"<<endl;

	cout << "Size = " << v.vec_size()<<endl;
   
	cout << "---------- empty ----------"<<endl;
	cout << "Empty = " << v.empty()<<endl;

    return 0;
}
