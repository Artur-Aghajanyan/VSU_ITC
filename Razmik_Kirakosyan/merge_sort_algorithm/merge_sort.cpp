#include <iostream>

int array[] = { 44, 3, 21, 5, 9, 7, 11, 99,72};
void merge_sort(int array[],int size) {
	int half1;
	int half2;
	if(size % 2 == 0) {
		half1 = size/2;
		half2 = size/2;
	}
	else {
		half1 = size/2 + 1;
		half2 = size/2;
	}

	int array1[half1];
	int array2[half2];

	for (int i = 0; i < half1; ++i) {
		array1[i] = array[i];
	}
	
	for (int i = half1; i < size; ++i) {
		array2[i] = array[i];
	}

int min, min_index;
for (int begin = 0; begin < half1; ++begin) {
	min = array1[begin];
	for (int i = begin + 1; i < half1; ++i)	{
		if (array1[i] < min) {
			min = array1[i];
			min_index = i;
	    }
	}

	array[min_index] = array[begin];
	array[begin] = min;
}

for ( int second = half1; second < size; ++second) {
	min = array2[second];
	for ( int i = second +1; i < size; i++) {
		if(array2[i] < min) {
			min = array2[i];
			min_index = i;
		}
	}

	array[min_index] = array[second];
	array[second] = min;
}

int i1 = 0, i2 = 0; 
for (int i = 0; i < size; ++i) {
	if (array1[i1] <= array2[i2] && i1 < half1) {
		array[i] = array1[i];
		i1++;
	}
	else if (i2 < half2) {
		array[i] = array2[1];
		i2++;
	}
}

for (int i = 0; i < size; ++i) {
	 std :: cout << array[i] << std :: endl;
}

}

int main () {
	merge_sort(array, 10);
	


	return 0;
}
