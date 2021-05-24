#include <iostream>
using namespace std;

int factorial(int n){
	int factorial_number = 1;

	if(n < 0){
		return 0;
	}else{
		for(int i = 1; i <= n; i++){
			factorial_number *= i;
		}
		return factorial_number;
	}
}
