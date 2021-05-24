#include <iostream>

int find_Pivot(int arr[], int begin, int end)
{
	int pivote = arr[end];
	int i = begin -1;
	int temp;
	for(int j = begin; j <= end-1; j++)
		{
			if(arr[j] < pivote)
				{
					i++;
					temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
}
			temp = arr[i+1];
			arr[i+1] = arr[end];
			arr[end] = temp;
		
return i+1;
}
void quic_Sort(int arr[], int begin, int end)
{
	if(begin >= end)
		return;
else {	
int p = find_Pivot(arr, begin, end);
	quic_Sort(arr, begin, p-1);
	quic_Sort(arr, p+1, end);
	}

}

int main()
{
	int arr[10] = {1, 12, 14, 11, 17, 2, 55, 5, 4, 10};
	quic_Sort(arr,0, 9);
    for(int i = 0; i < 10; ++i)
        {
            std::cout<<arr[i]<<" ";
        }
	return 0;
}
	
				
