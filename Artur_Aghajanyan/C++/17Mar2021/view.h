#ifndef VIEW_H
#define VIEW_H

#include <iostream>

class View {
    private:
        int x;
        int y;
        std :: string color;
    protected:
        View();
        View(int x, int y, std :: string color);
    public:
        int get_x();
        void set_x(int tmp);
        int get_y();
        void set_y(int tmp);
        std :: string get_color();
        void set_color(std :: string tmp);
        void print();
};

#endif

