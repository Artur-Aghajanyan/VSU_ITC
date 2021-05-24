#include <iostream>

void insertion(int* arr, int size){
	
    for (int i = 1; i < size; ++i)
    {
        int value = arr[i];
        int j = i - 1;
 
        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
}

int main() {
	int arr[] = {12,5,2,15,105,64,85,45,2485,48,852};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	for(int i = 0; i < size; ++i) {
		std::cout << "arr - " << arr[i]<<"\n";
	}
	std::cout << "****************\n";	
	insertion(arr, size);

	for(int i = 0; i < size; ++i) {
		std::cout << "arr - " << arr[i]<<"\n";
	}

	return 0;
}
