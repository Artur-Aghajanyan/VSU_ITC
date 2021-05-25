#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include "base.h"


class Text : public View
{
public:
    std::string text;
    std::string textColor;
    Text();
    Text(int x, int y, std::string c, std::string t, std::string tc);
    std::string getText();
    std::string getTextColor();
    void setText(std::string t);
    void setTextColor(std::string tc);
};

#endif            
