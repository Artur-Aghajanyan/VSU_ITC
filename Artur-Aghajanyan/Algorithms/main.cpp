#include <iostream>

void makePartition(int arr[], int l, int r);
void marge(int arr[], int l, int r, int size);

int main() {
	std::cout << "Please put size for array: ";
	int size;
	std::cin >> size;

	int arr[size];

	for(int i = 0; i < size; ++i) {
		arr[i] = rand()%100;
		std::cout << arr[i] << "\n";
	}
	std::cout <<"\n *****  After sort ***** "<< std::endl<<std::endl;
	makePartition(arr, 0, size-1);

	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << "\n";
	}
	return 0;
}


void makePartition(int arr[], int l, int r) {
	if(l < r){
		int mid = (r+l)/2;
	
		makePartition(arr, l, mid);
		makePartition(arr, mid+1, r);
		marge(arr, l, mid, r);
	}
}

void marge(int arr[], int l, int r, int size) {
	int left = r-l+1;
	int right = size-r;

	int arrLeft[left];
	int arrRight[right];
	
	for(int i = 0; i < left; ++i)
		arrLeft[i] = arr[l+i];

	for(int i = 0; i < right; ++i)
		arrRight[i] = arr[r+i+1];

	int count1 = 0;
	int count2 = 0;
	int j = 0;
	
	for(j = l; count1 < left && count2 < right; ++j){
		if(arrLeft[count1] < arrRight[count2]) {
			arr[j] = arrLeft[count1];
			count1++;
		}else{	
			arr[j] = arrRight[count2];
			count2++;
		}
	}	

	while(count1 < left){
		arr[j] = arrLeft[count1];
		count1++;
		j++;
	}

	while(count2 < right){
		arr[j] = arrRight[count2];
		count2++;
		j++;
	}
}
