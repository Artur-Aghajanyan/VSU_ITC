#include <iostream>
#include "double_list.h"


int main () {
	Double_linked_list obj;
	obj.push(88);
    obj.push(77);
	obj.push(55);
	obj.print();
	obj.pop();
	obj.print();
		
	return 0;
}
