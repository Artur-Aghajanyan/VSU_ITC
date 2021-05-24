#ifndef VIEW
#define VIEW
class View{
	private:
	int x;
	int y;
	std::string color;
	public:
	int getX();
	int getY();
	std::string getColor();
	void print();
	void setX(int x);
	void setY(int y);
	void setColor(std::string c);
	View();
	View(int x, int y);
};

#endif
