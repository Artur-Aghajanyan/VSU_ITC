#include <iostream>
#include "text.h"

Text::Text() : View()
{
    text = "red";
    textColor = "green";
}

Text::Text(int x, int y, std::string color, std::string t, std::string tc) 
{
   text = t;
   textColor = tc;
}

std::string Text::getText() { return text;}
std::string Text::getTextColor() { return textColor;}
void Text::setText(std::string text) { this-> text = text;}
void Text::setTextColor(std::string textColor) { this-> textColor = textColor;}


