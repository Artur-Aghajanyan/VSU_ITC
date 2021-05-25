#include <iostream>

class BinaryTree
{
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree ();
    BinaryTree (int value);
    BinaryTree *insert (int value, BinaryTree *);
    void print (BinaryTree * root);
    bool search(BinaryTree* root, int value);
};

BinaryTree::BinaryTree ()
{
    data = 0;
    left = nullptr;
    right = nullptr;
}

BinaryTree::BinaryTree (int value)
{
    data = value;
    left = nullptr;
    right = nullptr;
}

BinaryTree *
BinaryTree::insert (int value, BinaryTree * root)
{
    if (!root)
    {
        return new BinaryTree (value);
    }
    else if (value > root->data)
    {
        root->right = insert (value, root->right);
    }
    else
    {
        root->left = insert (value, root->left);
    }
    return root;
}

void
BinaryTree::print (BinaryTree * root)
{
    if (!root)
    {
        return;
    }
    print (root -> left);
    std::cout << root -> data << "  ";
    print (root -> right);
}

bool search(BinaryTree* root, int value)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (root -> data == value)
    {
        return true;
    }
    bool flag = false;
    if(root -> data > value)
    {
        flag = search(root -> left, value);
    }
    if(flag)
    {
        return true;
    }
    else
    {
        flag = search(root -> right, value);
    }

    return flag;
}
