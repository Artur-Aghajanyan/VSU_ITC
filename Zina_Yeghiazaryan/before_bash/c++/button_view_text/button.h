#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include "view.h"

class Button : public View {
	private:
	int width;
	int height;
	public:
	Button();
	Button(int width, int height);
	Button(int x, int y, std :: string color, int w, int h);
	void setWidth(int w);
	void setHeight(int h);
	int getWidth();
	int getHeight();
	void print();
};

#endif
