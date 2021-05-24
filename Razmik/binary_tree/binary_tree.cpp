#include <iostream>
#include "binary_tree.h"

binary_tree :: binary_tree() {
	root = nullptr;
}

void binary_tree :: insert(int key)
{
  if (root != nullptr) {
    insert(key, root);
  }
  else
  {
    root = new Treenode;
    root -> value = key;
    root -> left = nullptr;
    root -> right = nullptr;
  }
}

void binary_tree :: insert(int key, Treenode *leaf) {
	if(key < leaf -> value) {
  
    if(leaf -> left != nullptr) 
    	insert(key, leaf-> left);
    else {
    	leaf -> left = new Treenode;
      	leaf -> left -> value = key;
      	leaf -> left -> left = nullptr;    
      	leaf -> left -> right = nullptr;   
    }  
  }
  else if(key >= leaf -> value)
  {
    if(leaf -> right != nullptr)
      insert(key, leaf -> right);
    else
    {
      leaf -> right = new Treenode;
      leaf ->right -> value = key;
      leaf -> right -> left = nullptr; 
      leaf -> right -> right = nullptr;

    }
  }
}

void binary_tree :: print () {
	std :: cout << root -> value << std :: endl;	
}

