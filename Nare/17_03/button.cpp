#include <iostream>
#include "button.h"

Button::Button(){
    width = 0;
    height = 0;
}

Button::Button(int w, int h){
    width = w;
    height = h;
}

Button::Button(int x1, int y1, std::string color1, int w, int h )
 :View(x1, y1, color1){
    width = w;
    height = h;   
}

 void Button::print(){
    View::print();
    std::cout<<width<<" "<<height<<std::endl;
 }

 int Button::getWidth(){
    return width;
 }

 int Button::getHeight(){
    return height;
 }
