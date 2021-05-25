#include <iostream>

void merge_sort(int arr[], int size) {
	int half1;
	int half2;
	if(size % 2 == 0){
		half1 = size/2;
		half2 = size/2;
	}
	else {
		half1 = size/2 + 1;
		half2 = size/2;
	}

	int arr1[half1];
	int arr2[half2];
	for(int i = 0; i < half1; ++i) {
		arr1[i] = arr[i];
	}
	for(int i = half1; i < size; ++i) {
		arr2[i] = arr[i];
	}
	int min;
	int minIndex;
	for(int start =0; start < half1; ++start) {
		min = arr1[start];
		for(int i = start + 1; i < half1; ++i) {
			if(arr1[i] < min) {
				min = arr1[i];
				minIndex = i;
			}
		}
		arr[minIndex] = arr[start];
		arr[start] = min;
	}
	for(int start = half1; start < size; ++start) {
		min = arr2[start];
		for(int i = start + 1; i < size; ++i) {
			if(arr2[i] < min) {
				min = arr2[i];
				minIndex = i;
			}
		}	
		arr[minIndex] = arr[start];
		arr[start] = min;
	}
	int i1 = 0;
	int i2 = 0;
	for(int i = 0; i < size; ++i) {
		if(arr1[i1] <= arr2[i2] && i1 < half1) {
			arr[i] = arr1[i1];
			++i1;
		}
		else if(i2 < half2) {
		arr[i] = arr2[i2];
			++i2;
		}
	}
	
	for(int i = 0; i < size; ++i) {
		std :: cout << arr[i] << std :: endl;
	}
	
}

int main() {
	int arr[] = {12,11,4,70,6,45,21,50,14,3};
	 merge_sort(arr, 10); 

	return 0;
}













