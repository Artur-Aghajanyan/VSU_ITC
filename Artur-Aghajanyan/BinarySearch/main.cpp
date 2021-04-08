#include <iostream>
int res = false;

int foo(int* arr, int arrfirst, int arrlast, int number) {
	if(arrlast >= arrfirst){
		int midlast = arrlast/2;	
		int mid = arrfirst + (arrlast - arrfirst)/2;
		if(arr[mid] ==  number) {
			res = true;
			return 0;
		}
		if (arr[mid] > number){
			foo(arr, arrfirst, mid-1, number);
		}else{
			foo(arr, mid+1, arrlast, number);
		}
	}
}

int main() {
	int size, number = 0;

	std::cout << "Give me size for array: ";
	std::cin >> size;
	std::cout << "Give me number for search: ";
	std::cin >> number;

	int* array = new int[size];
	for(int i = 0; i < size; ++i) {
		array[i] = i+1;
		std::cout << array[i] << "\t";
		if(i%6 == 0 && i != 0) std::cout << std::endl;
	}

	foo(array, 0, size-1, number);

	std::cout << std::endl << std::endl;

	if(res) std::cout << "True, There is number like that!\n";
	else    std::cout << "False, There in not number like that!\n";
}
