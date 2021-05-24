#include <iostream>
#include "binary_tree.h"

int main () {
	binary_tree obj;
	obj.insert(3);
	obj.insert(7);
	obj.insert(77);
	obj.insert(111);
	obj.print();
	return 0;
}
