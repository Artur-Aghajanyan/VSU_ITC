#include <iostream>

using namespace std;

int func(int* arr,int s,int e,int n)
{
	int e1 = (s + e)/2;
	if(arr[e1] == n)
	{
		return e1;
	}
	else if(arr[e1] < n)
	{
		s = e1+1;
	}
	else
	{
		e = e1;
	}
	func(arr,s,e,n);
};

int main()
{
	int arr[20] = {1,3,5,8,17,25,39,85,100,125,145,156,178,190,201,256,278,305,309,356};
	cout<<func(arr,0,19,145)<<endl;
	return 0;
}
