#include <iostream>

class stack {
	private:
		int count;
		int* array;
	public:
		stack() {
			count = 0;
			array = new int[1000];
		}
			void push(int value) {
				if(count == 1000){
						std::cout << "array is full \n";
				return;
				}
				array[count] = value;
				++count;
			}
			void pop() {
				if(count == 0){
					std::cout << "this array is empty \n";
				}
				--count;
			}
			bool empty(){
				if(count == 0){
					return true;
				}
				return false;
			}		
		int operator[] (int index){
			return array[index];
		}
		int size(){
			return count;
		}
};

int main() {
	stack st;
	st.push(5);
	st.push(10);
	st.push(20);
	st.pop();
	st.size();
	std::cout << st.size() << std::endl;
	return 0;
}


