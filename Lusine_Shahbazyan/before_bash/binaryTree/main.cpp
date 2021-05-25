#include <iostream>
#include "binary.h"

int main ()
{
  BinaryTree tree;
  BinaryTree *root = nullptr;
  root = tree.insert (6, root);
  tree.insert (26, root);
  tree.insert (18, root);
  tree.insert (11, root);
  tree.insert (96, root);
  tree.insert (35, root);
  tree.print (root);
  std::cout << std::endl;
  std::cout << search(root, 18);
  std::cout << std::endl;
  return 0;
}

