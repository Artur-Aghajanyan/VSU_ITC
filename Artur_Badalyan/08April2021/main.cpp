#include <iostream>
#include "tree.h"
using namespace std;


int main() {
	
	Tree t;
	Tree *root = nullptr;	
	root = t.insert(root,40);
	t.insert(root,14);	
	t.insert(root,24);	
	t.insert(root,55);	
	t.insert(root,78);	
	t.insert(root,5);	
	t.insert(root,25);	
	t.insert(root,99);	
		
		
	t.printTree(root);
		
		
		
	return 0;
}
