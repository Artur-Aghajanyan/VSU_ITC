#include <iostream>
#include "factorial.h"
using namespace std;

int main(){
	int n;
	cout << "Give me number:  ";
	cin >> n;
	if(n > 0) {
		cout << factorial(n) << "\n";
	}else if(n == 0){
		cout << 0 << "\n";
	}
	else{
		cout << "Error! It is negative Number" << "\n";
	}
	return 0;
}
