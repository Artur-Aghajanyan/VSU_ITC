#include <iostream>
using namespace std;

int ways(int n) {	
	int building = 1;
	int space = 1;
	int p_countB;
	int p_countS;

	if (n == 1) {
		return 4;
	}

	for(int i = 2; i <= n; ++i) {
		p_countB = building;
		p_countS = space;
	
		space = p_countB + p_countS;
		building = p_countS;
	}

	int res = space + building;	
	

	return res*res;
}



int main() {
	int n;	
	cout<<"Write number ~ ";
	cin >> n;
	cout<<"Number of steps ~ "<<ways(n)<<endl;
	

	return 0;
}
