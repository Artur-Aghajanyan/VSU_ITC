#include <iostream>

void insertion (int *a, int size) {
	for (int i = 1; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] < a[j]) {
				int x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
		}
	}
}

int main() {
	int a[10] = {6, 7, 56, 3, 79, 12, 40, 15, 29, 47};
	insertion (a, 10);
	
	for (int i = 0; i < 10; ++i) {
		std :: cout << a[i] << ' ';
	}
}
