#ifndef VIEW_H
#define VIEW_H
#include <iostream>


class View{
	
	protected:
	int x;
	int y;
	std::string color;
	public:
	View();
	View(int x,int y);

	int getX();
	int getY();
	std::string getColor();
	
	void setX(int x);
	void setY(int y);
	void setColor(std::string color);
	virtual void print();

};

#endif
