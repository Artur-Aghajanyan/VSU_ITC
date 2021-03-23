#include <iostream>
#include "text.h"
#include "button.h"


int main(){
	
	Text t(7,8, "Hello");
	Button b(5,6);
	
	View** v = new View*[10];

	for(int i = 0; i < 10; i++){
		if (i < 6){
			v[i] = new Button();
		}else{
			v[i] = new Text();
		}
	}
	
	for(int i = 0; i < 10;i++){
		v[i]->setX(i+10);
		v[i]->setY(i+50);
		v[i]->setColor("red");
		v[i]->print();

	}

	delete[] v;	
	return 0;
}
