#include "stack.h"

Stack :: Stack() {
	count = 0;
	array = new int[1000];
}

void Stack :: push (int value) {
	array[count] = value;
	++count;
}
void Stack :: pop() {
	if (count == 0) {
	std :: cout << " There is  no any  element in the array " << std :: endl;
	}
	--count;
}
void Stack :: print () {
	for (int i = 0; i < count; ++i) {
	std :: cout << array[i] << std :: endl;
    }
}
int Stack :: size () {
	std :: cout << count << std :: endl;
	return count;

} 
