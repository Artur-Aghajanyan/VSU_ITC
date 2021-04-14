#include <iostream>
using namespace std;


void insertion(int *array,int size) {
			
	for (int i = 1;i < size;++i) {
        int in = array[i];
		int j = i - 1;
			
		while (in < array[j] && j >= 0) {
		array[j+1] = array[j];
		--j;
		}
		array[j+1] = in;
	}	
}




void printArray(int *array,int size){
	for(int i = 0;i < size;++i) {
		cout<<array[i]<<" ";
	}
}

int main() {
	int size = 8;	
	int array[] = {5,25,63,7,6,10,12,8};
	printArray(array,size);
	insertion(array,size);
	cout<<"\n-------Insertion sort--------------"<<endl;	
	printArray(array,size);
	return 0;
}
