#include <iostream>
#include "vector.h"


int main() {
	Vector<int> vector(15, 15);
	vector.push_back(150);
	vector.pop_back();
	vector.insert(14, 20);
	for(int i = 0; i < vector.size()-1; ++i)
		std::cout << vector[i]<< " - " << i << "\n";

	return 0;
}
