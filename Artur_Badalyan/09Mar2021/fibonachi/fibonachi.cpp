#include <iostream>
using namespace std;

int num1 = 0;
int num2 = 1;
int nextNum = 0;

int fib(int cinNum){
		
	if (cinNum == 0){
	cout << num1 << ", ";
	}
	if (cinNum == 1){
	cout << num2 << ", ";
	}

	for (int i = 0;i <= cinNum;i++){
	nextNum = num1 + num2;
	num1 = num2;
	num2 = nextNum;
	
	}

	return nextNum;

}
