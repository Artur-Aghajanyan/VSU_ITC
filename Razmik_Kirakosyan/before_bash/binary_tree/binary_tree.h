#ifndef BINARY_TREE_H
#define BINARY_TREE_H


struct Treenode {
	int value;
	Treenode* left;
	Treenode* right;
};


class binary_tree {
	private:
	Treenode* root;
	public:
	void insert(int key);
	void insert(int key,Treenode* leaf);
	void print ();
	binary_tree();

};

#endif
