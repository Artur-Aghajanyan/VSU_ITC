#include <iostream>
#include "view.h"


View::View(){}


View::View(int x,int y){
	this->x = x;
	this->y = y;
}



int View::getY(){
    return this->y;
}


int View::getX(){
	return this->x;
}

std::string View::getColor(){
	return this->color;
}




void View::setY(int y){
    this->y = y;	
}


void View::setX(int x){
	this->x = x;
}

void View::setColor(std::string color){
	this->color = color;
}


