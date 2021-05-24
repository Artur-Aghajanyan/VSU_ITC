#include <iostream>
#include "text.h"
#include "button.h"


int main(){
	
	Text t(7,8, "Hello");
	Button b(5,6);
	
	t.setX(45);
	t.setY(10);
	b.setX(17);
	b.setY(88);
	b.setW(100);
	b.setH(150);

    std::cout<<"Text --- " <<" x = " << t.getX() <<" y = " << t.getY() << " text = " << t.getT() <<"\n";
    std::cout<<"button --- " <<" x = " << b.getX() <<" y = " << b.getY() << " Width = " << b.getW() << " Height = "<< b.getH() <<"\n";

		
	return 0;
}
