#include <iostream>
#include <string>
#include "text.h"

Text :: Text() {
	text = "";
	textColor = "";
}

Text :: Text(std :: string text) {
	this -> text = text;
}

void Text :: setText(std :: string t) {
	text = t;
}

void Text :: setTc(std :: string tc) {
        textColor = tc;
}

std :: string Text :: getText() {
	return text;
}

std :: string Text :: getTc() {
	return textColor;
}

void Text :: print() {
	View :: print();
	std :: cout << text << ' ' << textColor << ' ';
}
