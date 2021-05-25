#include <iostream>
#include "view.h"
class Text : public View {
    private:
        std :: string text;
        std :: string text_color;
    public:
        Text();
        Text(int x, int y,std :: string color, std :: string t, std :: string t_c);
        std :: string get_text();
        void set_text(std :: string tmp);
        std :: string get_text_color();
        void set_text_color(std :: string tmp);
        void print();

};