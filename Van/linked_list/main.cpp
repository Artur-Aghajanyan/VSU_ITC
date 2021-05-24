#include <iostream>
#include "list.h"

int main(){
	List L;
	L.push(5);
	L.push(10);
	L.push(20);
	L.push(30);
	L.print();
	L.pop();
	L.print();
	return 0;
}
