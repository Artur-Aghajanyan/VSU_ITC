#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include "view.h"
class text:public view{
 public:
		 std::string tex;
		 std::string textcolor;
		 	text();
			text(std::string text, std::string textcolor,int x, int y, std::string color);
				
  };

#endif
