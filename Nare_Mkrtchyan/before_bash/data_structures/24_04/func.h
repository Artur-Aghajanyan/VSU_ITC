#include <iostream>
#include <string.h>
#include <stack>
#include <queue>

struct Node {
    std::string data;
    Node* left;
    Node* right;
};

Node* createRoot(std::string val);
Node* set_left_right(std::string val,Node* left_, Node* right_);
void revPolNot(std::string exp, int size);
void tree(std::queue<std::string> queue);
Node* printTree(Node* root);

