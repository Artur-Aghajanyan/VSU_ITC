#include <iostream>
using namespace std;

long factorial = 1;

int fact(int f){
	
	for(int i = 1;i <= f;i++){
		factorial *= i;
	}

	return factorial;	
}
