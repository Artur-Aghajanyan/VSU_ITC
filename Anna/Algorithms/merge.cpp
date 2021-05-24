#include <iostream>

void merge_sort(int arr[], int first, int last)
{
	if(last==first)
	return;

	int m = (last+first)/2;
	merge_sort(arr,first, m);
	merge_sort(arr, m+1, last);
	int i = first;
	int j = m + 1 ;
	int l = last - first + 1;
	int *arr1 = new int[l];
	for(int k = 0; k < l; ++k)
		{
			if(j > last || (i <= m && arr[i]< arr[j])){
	arr1[k] = arr[i];
	++i;
		}
			else
			{	
				arr1[k] = arr[j];
				++j;
			}
	}
	for(int k = 0, i = first; k < l; ++k, ++i)
		{
			arr[i] = arr1[k];
		}
	delete arr1;
}

int main ()
{

int arr[10] = {1,12,45,78,77,44,55,2,8,7};
merge_sort(arr, 0, 9);
for(int i = 0; i < 10; ++i)
{
	std::cout<<arr[i]<<" ";
}
return 0;
}
