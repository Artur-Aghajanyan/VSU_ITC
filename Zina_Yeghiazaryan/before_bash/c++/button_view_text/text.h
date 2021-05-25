#ifndef TEXT_H
#define TEXT_H
#include <cstring>
#include "view.h"

class Text : public View {
	private:
	std :: string text;
	std :: string textColor;
	public:
	Text();
	Text(std :: string text);
	void setText(std :: string t);
	void setTc(std :: string tc);
	std :: string getText();
	std :: string getTc();
	void print();
};

#endif
