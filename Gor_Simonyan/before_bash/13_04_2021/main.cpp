#include <iostream>

using namespace std;

void print(int* arr,int size)
{
        for(int i = 0; i < size; i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<""<<endl;
}

int quick(int* arr,int l,int r)
{
	int j = l - 1;
	for(int i = l; i < r; i++)
	{
		if(arr[i] < arr[r])
		{
			j++;
			int q = arr[j];
			arr[j] = arr[i];
			arr[i] = q;
		}
	}
	j++;
	int q = arr[r];
	for(int i = r; i >=j; i--)
	{
		arr[i] = arr [i-1];
	}
	arr[j] = q;
	
	return (j);
}

void quickSort(int* arr, int l,int r)
{
	if(l < r)
	{
		int p = quick(arr,l,r);
		quickSort(arr,l,p-1);
		quickSort(arr,p+1,r);
	}
}

void ins_sort(int* arr,int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[i] < arr[j])
			{
				int q = arr[i];
				for(int k = i; k > j; k--)
				{
					arr[k] = arr[k - 1];
				}
				arr[j] = q;
			}
		}
	}
}
int main()
{
	int arr[8] = {3,8,0,2,6,1,7,5};
	cout<<"___Array___"<<endl;
	print(arr,8);
	quickSort(arr,0,7);
	cout<<"___Quick___"<<endl;
	print(arr,8);
	ins_sort(arr,8);
	cout<<"___Insertion___"<<endl;
	print(arr,8);
	return 0;
}
