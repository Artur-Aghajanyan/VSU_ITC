#ifndef BASE_H
#define BASE_H
#include <iostream>

class View
{
public:
    int x;
    int y;
    std::string color;
    View();
    View(int x, int y);
    int  getX();
    int  getY();
    std::string  getColor();
    void setX(int x1);
    void setY(int y1);
    void setColor(std::string ci1);
};

#endif


