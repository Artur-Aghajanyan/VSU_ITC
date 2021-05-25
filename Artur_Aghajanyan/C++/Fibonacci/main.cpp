#include <iostream>
#include "fibonacci.h"
using namespace std;

int main(){
	int n;
	cout << "Give me number:  ";
	cin >> n;
	if(n <= 0){
		cout << "Error" << "\n";
	}else{
		cout << fibonacci(n)<< "\n";
	}
	return 0;
}
