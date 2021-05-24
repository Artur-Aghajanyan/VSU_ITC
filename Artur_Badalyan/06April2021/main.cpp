#include <iostream>
#include "stack.h"
using namespace std;



int main() {
	
	Stack<char> s;
	string text = "assadasd";
	int z = -1;
	for (int i = 0; i < text.size();i++){
		if (text[i] == '[' || text[i] == '{' || text[i] == '('){
			z = i;	
			s.push(text[i]);
		}else if(text[i] == ']' || text[i] == '}' || text[i] == ')'){
			if (s.top() == '[' && text[i] == ']')
					s.pop();
			else if (s.top() == '{' && text[i] == '}' )
					s.pop();
			else if (s.top() == '(' && text[i] == ')')
					s.pop();
			else{ 
			cerr << "ERROR!! in "<< i <<" index " <<endl;
			return 0;
			}
		}	
	}

	if (!s.empty()){
		cerr<<"ERROR Stack is not empty!! in "<<z<<" index" <<endl;
		return 0;
	}
	if (z == -1){
		cout << "In this text ther is not any brackets"<<endl;
	}

	
				
	cout << "Checking successfuly finished )))"<<endl;		

	return 0;	
}
