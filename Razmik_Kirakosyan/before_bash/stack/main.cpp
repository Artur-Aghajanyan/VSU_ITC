#include <iostream>
#include "stack.h"


int main() {
	Stack obj;
 	obj.push(7);
 	obj.push(11);
 	obj.push(77);
	obj.print();
	obj.pop();
	obj.print();
	obj.size();
	obj.print();

	
	return 0;
}
