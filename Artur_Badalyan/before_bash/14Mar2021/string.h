#include <iostream>


namespace ITC {

class string{
	
	public:

	friend std::ostream& operator<<(std::ostream& object, const string& string);

	
	string(const char* text);
	private:
	char* data;
	int size;

	

};
}
