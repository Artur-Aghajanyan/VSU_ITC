#ifndef VIEW_H
#define VIEW_H
#include <string>

class View {
	protected:
		int x;
		int y;
		std :: string color;
	public:
		View();
		View(int x, int y, std :: string color);
		void setX(int x1);
		void setY(int y2);
		void setColor(std :: string c);
		int getX();
		int getY();
		std :: string getColor();
		void print();
};

#endif
