#include <iostream>

int func (int* adr, int a, int b, int value) {
	int b1 = (a + b) / 2;
	
	if (value == adr[b1]) {
		return b1;
	} else if (value < adr[b1]) {
		func (adr, a, b1, value);
	} else {
		func (adr, b1 + 1, b, value);
	}
}

int main() {
	int array[20] = {1, 3, 5, 6, 7, 23, 34, 60, 78, 100, 101, 103, 105, 106, 107, 123, 134, 160, 178, 200};
	std :: cout << func (array, 0, 19, 200);
}
