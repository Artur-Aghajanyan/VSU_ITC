#include <iostream>

int arr[5] [5] =  { {0, 3, -1, 4, -1},
			        {3, 0, -1, -1, -1},
					{-1, -1, 0, 5, -1},
    				{4, -1, 5, 0, 6},
					{-1, -1, -1, 6, 0}};

int arr1[5] = {0, 3, -1, 4, -1};
void graph() {
	for(int i = 1; i < 5; ++i) {
			if(arr[0][i] == -1) {
				continue;
			}
		for(int j = 0; j < 5; ++j) {
			if(arr[i][j] == -1) {
				continue;
			}
			arr[i][j] = arr[i][j] + arr[0][i];
			if(arr1[j] == -1 || arr1[j] > arr[i][j]) {
				arr1[j] = arr[i] [j];
			}
		}
	}
	for(int i = 0; i < 5; ++i) {
			std :: cout << arr1[i] << std :: endl;
	}
}

int main() {
	graph();
	return 0;
}
