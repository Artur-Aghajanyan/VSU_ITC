#include <iostream>
using namespace std;

class Tree {
	public:	
	Tree();
	Tree(int data);
	Tree* insert(Tree* root,int data);
	void printTree(Tree* root);
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
