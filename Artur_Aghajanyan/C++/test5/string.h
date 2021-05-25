#include <iostream>

namespace ITC{
	class String{
		private:
		int size;
		char* data;

		public:
		String();
		String(const char* text);
		void print(){
			std::cout<<"Size = "<<this->size<<std::endl;
			std::cout<<"Text = "<<this->data<<std::endl;
		}
 		friend std::ostream& operator<<(std::ostream& os, const String& string); 
		~String();
	}; 
}
