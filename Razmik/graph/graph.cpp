#include <iostream>

int array_1 [5] [5] ={ {0, 3, -1, 4, -1},
					 {3, 0, -1, -1, -1},
					 {-1, -1, 0, 5, -1},
					 {4, -1, 5, 0, 6},
					 {-1, -1, -1, 6, 0}};


int array_2[5] = {0, 3, -1, 4, -1};
void graph() {
	for (int i = 1; i < 5; ++i) {
		if(array_1[0][i] == -1){
			continue;
		}
		for (int j = 0; j < 5; ++j) {
			if(array_1[i][j] == -1) {
				continue;
			}
			array_1[i][j] = array_1[0][i] + array_1[i][j];		
			if (array_2[j] == -1 || array_2[j] > array_1[i][j]) {
				array_2[j] = array_1[i][j];
			}
			
			 		

		}
	
	}
	
	for (int i = 0; i < 5; ++i) {
		std :: cout << array_2[i] << std :: endl;
	
	}
}

int main () {
	graph();
	return 0;
	
}
