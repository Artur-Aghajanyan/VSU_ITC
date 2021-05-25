#include <iostream>

int  search(int *arr, int first, int last, int value)
{
	if(last >= first){
	int a = (last+first)/2;
	if(value == arr[a])
		return a;
	else
		if(value < arr[a])
			return search(arr, first, a-1, value);
		else
			return  search(arr, a+1, last, value);
	}
	
		return -1;
}
int main()
{
int array[25] = {12, 15,16, 17, 18, 19, 20, 21, 24, 25, 27, 28, 30, 31, 45, 55, 77, 78, 79, 80, 87, 91, 92, 97, 99};
int s = search(array, 0, 24, 100);
if(s == -1)
std::cout<<"Array does not contain this value";
else
std::cout<<"Array conains this value";
return 0;
}
