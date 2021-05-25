#include <iostream>
using namespace std;

 
int binarySearch(int arr[], int left, int right, int value)
{
    while (left <= right) {
        int m = left + (right - left) / 2;
  
        if (arr[m] == value)
            return m;
  
        if (arr[m] < value)
            left = m + 1;
  
        else
            right = m - 1;
    }
  
    return -1;
}
  
int main(void)
{
    int array1 [] = {1, 3, 5, 6, 7, 23, 34, 60, 78, 100, 101, 103, 105, 106, 107, 123, 134, 160, 178, 200};
    int num;
    int size = sizeof(array1) / sizeof(array1[0]);
	cout << "Write number for search in array"<<endl;
	cin >> num;
    int result = binarySearch(array1, 0, size - 1, num);


	
	if (result == -1)
		cout << "there is no element with this value"<<endl;
    else
		cout << "Element is present at index " << result<<endl;
    
	return 0;
}
