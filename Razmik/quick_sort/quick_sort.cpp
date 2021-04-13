#include <iostream>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
 
int partition(int array[], int l, int r) {
	int i = l-1;
	int j = l;
	int pivot = array[r];
	for (j = l; j <= r-1; ++j) {
		if(array[j] < pivot) {
			++i;
			swap(&array[j],&array[i]);
		}
	}
	swap(&array[i+1], &array[r]);
	return i+1;
}

void quick_sort(int array[], int l, int r) {
	if (l <= r){
		int piv_ad = partition(array, l, r);
		quick_sort(array, l, piv_ad-1);
		quick_sort(array, piv_ad+1, r);
	}
}

void print(int array[]) {
	for(int i = 0; i < 5; ++i) {
		std :: cout << array[i] << "  ";
	}
	std :: cout << std :: endl;
}
	

int main() {
	int array[] = {12, 78, 24, 43, 56};
	quick_sort(array, 0, 4);
	print(array);	
	
	
	
	return 0;
}
