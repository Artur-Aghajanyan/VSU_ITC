#include <iostream>
#include "view.h"
#include "text.h"
#include "button.h"
int main(){
	View view;
	view.setX(15);
	std::cout<<view.getX();
	view.print();
	Text text;
	text.print();
	return 0;
}
