#ifndef VIEW
#define VIEW

#include <iostream>
class View{
    private:
        int x;
        int y;
        std::string color;
    public:
        View();
        View(int x, int y);
        View(int x1, int y1, std::string color1);
        void print();
        int getX();
        int getY();
        std::string getColor();
};

#endif
