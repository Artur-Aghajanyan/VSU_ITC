#include "button.h"


button::button():view(){
		width=0;
		height=0;
}	

button::button(int w, int h, int x, int y,std::string color):view(x, y, color){
		width=w;
		height=h;
 }	
