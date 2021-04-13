#include <iostream>

int quick(int* arr, int l, int r) {
	
	for(int i = 0; i < r; ++i){
		if(arr[i] < arr[r]){
			int temp = arr[i];
			arr[i] = arr[l];
			arr[l] = temp;
			l++;
		}
	}
	int temp = arr[r];
	arr[r] = arr[l];
	arr[l] = temp;
	return l;
}

void quickSort(int* arr, int start, int end) {
	if(start < end){
		int index = quick(arr, start, end);
//		quickSort(arr, start, index-1);
//		quickSort(arr, index+1, end);
	}
}

int main() {
	int array[] = {12,1,3,5,4,9,8,7};
	int size = sizeof(array)/sizeof(array[0]);
	for(int i = 0; i < size; ++i){
		std::cout << array[i] << " - value\n";
	}
	std::cout << "*****************\n";
	quick(array, 0, size-1);
	for(int i = 0; i < size; ++i){
		std::cout << array[i] << " - value\n";
	}
	return 0;
}

