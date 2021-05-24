#include <iostream>
#include "stack.h"


Stack :: Stack () {
	array = new char[100];
	count = 0;
} 	

void Stack :: push (char value) {
	array[count] = value;
	count++;	
}

void Stack :: pop () {
	count--;

}
bool Stack :: check (char bracket) {
	if (count == 0) {
	return false;
	}
	if ((array[count - 1] == '[' && bracket == ']') || (array[count -1] == '(' && bracket == ')') || (array[count-1] == '{' && bracket == '}')) {
			pop();
			return true;
	 }
			return false; 
}

bool Stack :: check_array() {
	if (count == 0) {
		return true;
	}
	 	return false;
}
