#include <iostream>
#include "binar.h"

int main() {
	Binary bin;
	Binary *root = nullptr;
	root = bin.insert(root,15);
	bin.insert(root, 20);
	bin.insert(root, 22);
	bin.insert(root, 23);
	bin.insert(root, 25);
	bin.insert(root, 60);
	bin.insert(root, 70);
	bin.print(root);
	return 0;
}
