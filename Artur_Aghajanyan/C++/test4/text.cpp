#include <iostream>
#include "view.h"
#include "text.h"

Text::Text(){

}

Text::Text(std::string text1, int x1, int y1):View(x1, y1){
	this->text = text1;
}

void Text::setText(std::string t){
	this->text = t;
}

void Text::setTextColor(std::string tc){
	this->textColor = tc;
}

std::string Text::getText(){
	return text;
}
std::string Text::getTextColor(){
	return textColor;
}
void Text::print(){
	View::print();
	std::cout << "*** Print Text ***\nText = "<< text << "\nText color = " << textColor<<std::endl;

}
