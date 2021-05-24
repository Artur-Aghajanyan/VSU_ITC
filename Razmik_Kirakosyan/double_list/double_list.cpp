#include <iostream>
#include "double_list.h"


Double_linked_list :: Double_linked_list() {
	begin = nullptr;

	 
}

void Double_linked_list :: push(int val) {
	Node* new_node = new Node();
	new_node -> previous = nullptr;
	new_node -> next = nullptr;
	new_node -> value = val;
	if(begin == nullptr) {
		begin = new_node;
		return;
	}
	Node* end = begin;
	while(end ->next != nullptr) {
		end = end -> next;
	}
    end -> next = new_node;
	new_node -> previous = end;
}

void Double_linked_list :: pop() {
	if(begin == nullptr) {
    	std :: cout << "There is no any node in double_linked_list" << std :: endl;
         return;
    }
	Node* end = begin;
	while(end -> next !=nullptr ) {
		end =  end -> next;
	}	
    end = end -> previous;
	delete end -> next;
	end -> next = nullptr;
}

void Double_linked_list :: print () {
	if(begin == nullptr) {
		std :: cout << "There is no any value for printing" << std :: endl;
		return;
	}
	Node* end = begin;
	while(end != nullptr) {
    	std :: cout << end -> value << std :: endl;
		end = end -> next;
	}
}


