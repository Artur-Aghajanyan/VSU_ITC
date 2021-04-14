#include <iostream>

void insertion (int* array) {
	int n = 7;
	for (int i = 1; i < n; ++i) {
		int temp = array[i];
	 	int j = i;
		while(j > 0 && array[j-1] > temp) {
			array[j] = array[j-1];
			j = j-1;
		}
		array[j] = temp;
	}
	
	for (int i = 0; i < n; ++i) {
		std :: cout << array [i] << std :: endl;
	}
}

int main() {
	int array[] = {22, 11, 55, 66, 33, 44, 77};
	insertion(array);


	return 0;
}
