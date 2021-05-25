#include <iostream>

void insertion (int* arr) {
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < size; ++i) {
		while(i > 0 && arr[i-1] > arr[i]) {
			int temp = arr[i];
			arr[i] = arr[i-1];
			i = i-1;
		}
	}

	for (int i = 0; i < size; ++i) {
		std :: cout << arr[i] << std :: endl;
	}
}

int main() {
	int arr[] = {22, 11, 55, 66, 33, 44, 77};
	insertion(arr);


	return 0;
}
