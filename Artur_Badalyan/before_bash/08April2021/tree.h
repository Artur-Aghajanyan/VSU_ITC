#include <iostream>
using namespace std;

class Tree {
	public:	
	Tree();
	Tree(int data);
	Tree* insert(Tree* root,int data);
	void printTree(Tree* root);
	int search(Tree* root,int data);
	private:
	int data;
	Tree *left, *right;
};



Tree::Tree() {
	this->data = 0;
	this->left = this->right = nullptr;
}

Tree::Tree(int data) {
	this->data = data;
	this->left = this->right = nullptr;
}

int Tree::search(Tree* root,int data) {
	
	if (!root) {
		return 0;
	}
	if (root->data == data){
		return root->data;
	}

	if (data < root->data) {	
		return search (root->left,data);
	}
	
	if (data > root->data) {
		return  search(root->right,data);
	}
}

Tree* Tree::insert(Tree* root,int data) {
	if (!root) {
		 return new Tree(data);
	}

	if (data < root->data) {
		root->left = insert(root->left, data);
	}
	if (data > root->data) {
		root->right = insert(root->right, data);
	}
	
	return root;	
}

void Tree::printTree(Tree* root) {
	if (!root){
		return;
	}
	printTree(root->left);
	cout << root->data<<"\t";
	printTree(root->right);
}
