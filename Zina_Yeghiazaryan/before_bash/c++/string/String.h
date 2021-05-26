#include <ostream>
#include <iostream>
namespace itc {
	class String {
		private:
			char* data;
			int size;
		public:
			String (const char* text);
			friend std :: ostream& operator << (std :: ostream& out, const String& text);
	                ~String ();
	};
	//std :: ostream& operator << (std :: ostream& out, const String& text);
}
std :: ostream& operator << (std :: ostream& out, const String& text);
