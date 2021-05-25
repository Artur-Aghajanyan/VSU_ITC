#include <iostream>
#include "list.h"
List::List(){
	begin = nullptr;
}		
void List::push(int value){
	Node* node = new Node();
	node->next = nullptr,
	node->previous = nullptr;
	node->value = value;
	if(begin == nullptr){
		begin = node;
		return;
	}
	Node* end = begin;
	while(end->next != nullptr){
		end = end->next;
	}
	end->next = node;
	node->previous = end;
}
void List::pop(){
	if(begin == nullptr){
		std::cout << "the List is empty \n";
		return;
	}
	Node* end = begin;
	while(end->next != nullptr){
		end = end->next;
	}
	end = end->previous;
	delete end->next;
	end->next = nullptr;
}
void List::print(){
	Node* end = begin;
	while(end != nullptr){
		std::cout << end -> value <<std::endl;
		end = end->next;
	}
}
