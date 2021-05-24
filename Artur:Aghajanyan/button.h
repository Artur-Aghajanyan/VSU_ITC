#ifndef BUTTON
#define	BUTTON

#include "view.h"


class Button:public View{
	protected:
	int width;
	int height;
	public:
	int getW();
	int getH();
	void print();
	void setW(int w);	
	void setH(int h);
	Button();
	Button(int w, int h);
	Button(int x, int y, int w, int h);
};
#endif
