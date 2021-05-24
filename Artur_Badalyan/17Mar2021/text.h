#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include "view.h"

class Text:public View{
	
	protected:
	std::string text;
	std::string textColor;
	public:
	Text();

	Text(int x,int y,std::string text);

	int getX();
	int getY();
	std::string getT();
	std::string getColor();
	
	void setX(int x);
	void setY(int y);
	void setT(std::string text);
	void setColor(std::string textColor);
};

#endif
