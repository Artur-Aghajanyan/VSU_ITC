#include <iostream>
#include "text.h"

Text::Text(){
    text = "";
    text_color = "";
}

Text::Text(std::string text){
    text = text;
    text_color = "";
}

Text::Text(std::string text, std::string text_color){
    text_color = text_color;
    text = text;
}

Text::Text(int x1, int y1, std::string color1, std::string text1, std::string text_color1):View(x1,y1){
    text = text1;
    text_color = text_color1;
}

void Text::print(){
    View::print();
    std::cout<<text<<" "<<text_color<<std::endl;
}

std::string Text::getText(){
    return text;
}

std::string Text::getTextColor(){
    return text_color;
}
