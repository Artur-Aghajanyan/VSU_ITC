#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "view.h"
class button:public view{
	public:
	int width;
	int height;
		button();
		button(int w, int h, int x, int y,std::string color);
 };

#endif

