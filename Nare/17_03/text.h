#ifndef TEXT
#define TEXT

#include "view.h"
class Text: public View{
        std::string text;
        std::string text_color;
    public:
        Text();
        Text(std::string text);
        Text(std::string text, std::string text_color);
        Text(int x1, int y1, std::string color1, std::string text1, std::string text_color1);
        void print();
        std::string getText();
        std::string getTextColor();
};
#endif
