#ifndef BUTTON_H
#define BUTTON_H
#include "base.h"

class Button : public View
{
public:
    int width;
    int height;
    Button();
    Button(int width, int height);
    Button(int x, int y, int w, int h);
    int getWidth();
    int getHeight();
    void setWidth(int w);
    void setHeight(int h);
};

#endif
