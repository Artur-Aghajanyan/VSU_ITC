#include <iostream>
#include "list.h"
using namespace std;



int main(){
	
	List<int> l;
	l.push(5);
	l.push(45);	
	l.push(145);
	l.push(457);
	l.printList();
	cout<<"-----erase index 0------"<<endl;
	l.erase(0);
	l.printList();	
	cout<<"------insert in index 2-------"<<endl;	
	l.insert(2,777);
	l.printList();	
	return 0;
}
