#include <iostream>
using namespace std;


int sum = 0;
int mean(int num){
	
	int* array = new int[num];


	for(int i = 0;i < num;i++){
		array[i] = rand() % 100;
	}

	for (int i = 0;i < num;i++){
		sum += array[i];
	
	}

	cout << sum << " ";

	return 0;

}

