#include <iostream>
using namespace std;

int fibonacci(int n){
	int a = 0;
	int b = 1;
	int c;
	for(int i = 3;i<=n;i++){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int factorial(int k){
	int s = 1;
	for(int i = 1;i<=k;i++){
		s = s * i;	
	}
	return s;
}

float average(int k)
{

        float s = 0;
	int* array = new int[k];
        for(int i = 0;i<k;i++)
        {
                cin>>array[i];
                s += array[i];
        }
        cout<<"average - ";
        return s/k;

}

