#include "text.h"


text::text():view(){
		tex=" ";
		textcolor=" ";
}

text::text(std::string text, std::string textcolor,int x, int y, std::string color):view(x,y,color){
		this->tex=text;
		this->textcolor=textcolor;
}			
