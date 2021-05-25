#include <iostream>
#include "factorial.h"
using namespace std;


int n;
int main(){

	cout << "Enter a positive number: ";
	cin >> n;
	
	if (n < 0){
		cout << "Factorial of a negative number doesn't exist.";
	}else{	
	        cout << "This number of factorial = " << fact(n) << "\n";
	}

	return 0;
}
