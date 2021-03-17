#ifndef TEXT
#define TEXT
#include "view.h"
class Text:public View{
	protected:
	std::string text;
	std::string textColor;
	public:
	std::string getText();
	std::string getTextColor();
	void print();
	void setText(std::string t);
	void setTextColor(std::string tc);
	void setter(std::string text, std::string textColor);
	Text();
	Text(std::string text, int x1, int y1);
};
#endif
