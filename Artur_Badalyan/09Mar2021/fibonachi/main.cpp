#include <iostream>
#include "fibonachi.h"
using namespace std;


int cinNum;
int main(){
	
	cout << "Enter the number\n";
	cin >> cinNum;
	
	cout << "This number of fibonacci = " << fib(cinNum) << "\n";

	return 0;
}
