#ifndef BUTTON
#define BUTTON

#include "view.h"

class Button: public View{
         int width;
         int height;
    public:
        Button();
        Button(int w, int h);
        Button(int x1, int y1, std::string color1, int w, int h );
        void print();
        int getWidth();
        int getHeight();
};

#endif
