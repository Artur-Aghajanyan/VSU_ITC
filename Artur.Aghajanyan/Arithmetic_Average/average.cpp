#include <iostream>

using namespace std;

int average(int x){
	int* arr = new int[x];
	float count = 0;
	for(int i = 0; i < x; i++){
		arr[i] = rand() % 100;
		cout << arr[i] << "\n";
	}
	for(int i = 0; i < x; i++){
		//cout << arr[i] << "----n"<< endl;
		count += arr[i];
	}
	return count/x;
}	
