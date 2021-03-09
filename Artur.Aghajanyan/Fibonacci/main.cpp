#include <iostream>
#include "fibonacci.h"
using namespace std;

int main(){
	int n;
	cout << "Give me number:  ";
	cin >> n;
	cout << fibonacci(n)<< "\n";
	return 0;
}
