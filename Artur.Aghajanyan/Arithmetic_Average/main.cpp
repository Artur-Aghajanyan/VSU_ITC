#include <iostream>
#include "average.h"
using namespace std;

int main(){
	int x;
	cout << "Give me number:  ";
	cin >> x;
	if(x > 0){
		cout << average(x)<<endl;
	}else{
		cout << "Error!, This is number negative !!" << "\n";
	}
	return 0;
}
