#include "view.h"
#include <iostream>
View::View(){
    x = 0;
    y = 0;
    color = "";
}

View::View(int x, int y){
    this->x = x;
    this->y = y;
    color = "";
 }

View::View(int x1, int y1, std::string color1){
    x = x1;
    y = y1;
    color = color1;
 }

 void View::print(){
    std::cout<<x<<" "<<y<<" "<<color<<std::endl;
 }

 int View::getX(){
    return x;
 }

 int View::getY(){
    return y;
 }
std::string View::getColor(){
    return color;
 }
