#include <iostream>
#include "text.h"
#include "view.h"

Text::Text(){}



Text::Text(int x,int y,std::string text):View(x,y){
		this->text = text;
 }


int Text::getY(){
    return this->y;
}


int Text::getX(){
	return this->x;
}

std::string Text::getT(){
	return this->text;
}

std::string Text::getColor(){
	return this->textColor;
}




void Text::setY(int y){
    this->y = y;	
}


void Text::setX(int x){
	this->x = x;
}

void Text::setT(std::string text){
	this->text = text;
}

void Text::setColor(std::string textColor){
	this->textColor = textColor;
}


