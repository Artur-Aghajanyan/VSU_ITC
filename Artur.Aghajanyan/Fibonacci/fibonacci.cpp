#include <iostream>
using namespace std;

int fibonacci(int n){
	int count = 0;
	if(n == 0 || n == 1){
		count += 1;
	}
	else if(n > 0){
		int F1 = 0;
		int F2 = 1;
		count = 1;
		for(int i = 2; i < n; i++){
			count = F1 + F2;
			F1 = F2;
			F2 = count;
		}
	}
	return count;
}
