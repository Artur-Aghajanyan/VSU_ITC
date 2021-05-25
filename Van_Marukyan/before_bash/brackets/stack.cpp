#include <iostream>

class Stack {
	char* array;
	int count;
		public:
			Stack(){
			array = new char[1000];
			count = 0;
			}
			void push(char value){
				array[count] = value;
				++count;	
			}
			void pop(){
				--count;
			}
			bool check(char a){

					if(count == 0){
						return false;
					}
				if( ( array[count -1] == '{' && a == '}') || ( array[count - 1] == '(' && a == ')' ) || ( array[count - 1] == '[' && a == ']' ) ){
					pop();
					return true;
				}
				else {
					return false;
				}
			}
			bool is_empty(){
				if(count == 0){
					return true;
				}
				else {
					return false;
				}
			}
};

int main(){
	Stack S;
	std::string x = "{das(dfd[s(sdc(sddcs{dccsddcsd}}DScsdDsDcdcSDCdcs";
			for(int i = 0; i < x.length(); ++i){
				if(x[i] == '{' || x[i] =='(' || x[i] == '['){
					S.push(x[i]);
				}
				else if(x[i] == '}' || x[i] ==')' || x[i] == ']') {
					if(!S.check(x[i])){
						std::cout <<"the error index is " << i << std:: endl;
						return 0;
					}
				}
			}
			if(!S.is_empty()){
				std::cout << "the opening bracked are more then closeing" <<std::endl;
			}
	return 0;
}
