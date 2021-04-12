#include <iostream>
template <class T>
struct Node{
	T value;
	Node* next;
	Node* prev;
};

template <class T>
class List{
	private:
		Node<T>* head;
		Node<T>* bottom;
		int size;
	public:
		List();
		void pop();
		void print();
		void push(T value);
		void erase(int index);
		void insert(int index, T value);
};

template <class T>
List<T>::List() {
	this->head = nullptr;
	this->bottom = nullptr;
	this->size = 0;
}

template <class T>
void List<T>::push(T value) {
	Node<T>* node = new Node<T>;
	node->next = nullptr;
	node->value = value;
	Node<T>* last = head;
	while(last && last->next) {
		last = last->next;
	}

	if(!last) {
		this->head = node;
		node->prev = nullptr;
	}
	else {
		this->bottom = node;
		last->next = node;
		node->prev = last;
	}
	this->size++;
}

template <class T>
void List<T>::print() {
	std::cout << "Give me for number: ";
	int number;
	std::cin >> number;
	Node<T>* node = head;
	int counter = 0;
	for(int i = 0; i < this->size; ++i) {
		std::cout << node->value << " - value\n";
		node = node->next;
	}	
	/*for(int i = 0; i < this->size; ++i){
		counter++;
		if(number == node->value) {
		   	std::cout << "Number of: " << node->value << "\nCounter: " << i << "\n";
			return;
		}
		else 
			node = node->next;
	}*/
	/*for(int i = 0; i < this->size; ++i){
		for(int j = 0; j < i-1; ++j){
			if(node->value < node->next->value) {
				node->next = node
			}
		}
	}
	std::cout << "There is not number like that.\nCounter: "<< counter << "\n"; */
}

template <class T>
void List<T>::pop() {
	Node<T>* last = this->bottom->prev;
	delete bottom;
	bottom = last;
	last->next = nullptr;
	--this->size;
}

template <class T>
void List<T>::erase(int index) {
	if(size/2 > index){
		Node<T>* node = head;
	
		if(index == 0) {
			Node<T>* last = node->next;
			delete node;
			last->prev = nullptr;
			head = last;
		}
		else{
			for(int i = 1; i < index; ++i){
				node = node->next;
			}

			Node<T>* last = node->next;
			node->next = last->next;
			last->prev = node;
			delete last;
		}
	}else {
		Node<T>* node = bottom;
		for(int j = size; j > index; --j){
			node = node->prev;
		}	
		Node<T>* last = node->next;
		node->next = last->next;
		last->prev = node;
	}

	--this->size;
}

template <class T>
void List<T>::insert(int index, T value) { 
	if(this->size < index) return;
	
	Node<T>* temp = new Node<T>;
	temp->value = value;
	
	if(this->size/2 > index){
		Node<T>* node = head;
		
		for(int i = 0; i < index-1; ++i){
			node = node->next;
		}	

		temp->next = node->next;
		node->next->prev = temp;
		node->next = temp;
		temp->prev = node;
	}else {
		Node<T>* node = bottom;
		
		for(int i = size; i > index; --i){
			node = node->prev;
		}

		temp->next = node->next;
		node->next->prev = temp;
		node->next = temp;
		temp->prev = node;
	}

}

void sort(int* array, std::string type, std::string minOrMax){
	if(minOrMax == "min"){
		if(type == "desc"){
			for(int i = 0; i < 10; ++i){
				int index = i;
				for(int j = i+1; j < 10; ++j){	
					if(array[index] > array[j]) {
						index = j;
					}

				}
				std::cout << "DESC _ MIN ---- " << array[index] << "\n";
				int temp = array[i];
				array[i] = array[index];
				array[index] = temp;
			}		
			std::cout << "\n";
		}
		else if(type == "asc") {
			for(int i = 0; i < 10; ++i){
				int index = i;
				int min = array[i];
				for(int j = i+1; j < 10; ++j){	
					if(min > array[j]) {
						index = j;
						min = array[j];
					}

				}
				std::cout << "ASC _ MIN ---- " << array[index] <<"\n";
				int temp = array[i];
				array[i] = min;
				array[index] = temp;
			}	
			std::cout << "\n";
		}
		
	} else if(minOrMax == "max") {
		if(type == "asc") {
			for(int i = 0; i < 10; ++i){
				int index = i;
				int max = array[i];
				for(int j = i+1; j < 10; ++j){	
					if(max < array[j]) {
						index = j;
						max = array[j];
					}

				}
				std::cout << "ASC _ MIN ---- " << array[index] <<"\n";
				int temp = array[i];
				array[i] = max;
				array[index] = temp;
			}	
			std::cout << "\n";		
		}else if(type == "desc") {
			for(int i = 0; i < 10; ++i){
				int index = i;

				for(int j = i+1; j < 10; ++j){	
					if(array[index] < array[j]) {
						index = j;
					}

				}
				std::cout << "DESC _ MAX ---- " << array[index] << "\n";
				int temp = array[i];
				array[i] = array[index];
				array[index] = temp;
			}	
			std::cout << "\n";
		} 
	}


/*	std::cout << "***********\n";
	for(int i = 0; i < 10; ++i){
		std::cout << array[i] << " - value\n";
	}*/
}


int main() {
	List<int> list;
	int array[10] = {1,2,3,4,5,6,7,9,8,10};
	for(int i = 10; i < 0; --i){
		list.push(rand()%100);
		//array[10-i] = i;
	}
	//list.print();
	
	int counter = 0;
	
	
	for(int i = 0; i < 10; ++i){
		std::cout << "Arr - " << array[i] << "\n";
	}	

/*	for(int i = 0; i < 10; ++i){
		bool res = true;
		for(int k = 0; k < 10-1; ++k){
			if(array[k] > array[k+1]){
				res = false;
				break;
			}
		}

		if(!res) {
			for(int j = 0; j < 10-i-1; ++j){
				if(array[j] > array[j+1]){
					int temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
				counter++;
			}
		
		}else{
			break;
		}
	}
*/





	sort(array, "asc", "min");
	sort(array, "desc", "min");

	sort(array, "asc", "max");
	sort(array, "desc", "max");
	//std::cout << "Number of count " << counter<<"\n";
	return 0;

}
