#include <iostream>
#include "view.h"

class Button : public View {
    private:
        int width;
        int height;
    public:
        Button();
        Button(int w, int h);
        Button(int x, int y, int w, int h, std :: string c);
        int get_width();
        void set_width(int tmp);
        int get_height();
        void set_height(int tmp);
        void print();
};