#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "view.h"

class Button:public View{
		protected:
	int width;
	int height;
	std::string color;
		public:
	Button();
	Button(int w,int h);
	Button(int x,int y,int w,int h);

	int getX();
	int getY();
	int getW();
	int getH();

	void setX(int x);
	void setY(int y);
	void setW(int w);
	void setH(int H);
	
};

#endif
