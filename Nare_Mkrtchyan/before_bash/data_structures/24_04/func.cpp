#include "func.h"
//create one node
Node* createRoot(std::string val)
{
    Node* newnode = new Node();
    newnode -> data = val;
    newnode -> left = nullptr;
    newnode -> right = nullptr;

    return newnode;
}

//create tree with given root, left and right leaves
Node* set_left_right(std::string val,Node* left_, Node* right_) {
    Node* node = new Node();
    node -> data = val;
    node -> left = left_;
    node -> right = right_;

    return node;
}

//make expression postfix 
void revPolNot(std::string exp, int size) {
    std::stack<char> stack;
    std::queue<std::string> queue;

    std::string num = "";
    for(int i = 0; i < size; ++i) {
        if(isdigit(exp[i]) && i != size-1) {
            num.push_back(exp[i]);
            continue;
        }
        else
        if(num != "") {
            queue.push(num);
            num = "";
        }
        else if(i == size - 1) {
            num.push_back(exp[i]);
            queue.push(num);
        }

         if (exp[i] == '(') {
            stack.push(exp[i]);
            continue;
        }
        else if(exp[i] == ')') {
            while(stack.top() != '(') {
                std::string s;
                s = stack.top();
                queue.push(s);
                stack.pop();
            }
            stack.pop();
            continue;
        }
        else if(exp[i] == '+' || exp[i] == '-') {
            while(!stack.empty() && (stack.top() == '*' || stack.top() == '/' || stack.top() == '-' || stack.top() == '+')) {
std::string s;
                s = stack.top();
                    queue.push(s);
                    stack.pop();
            }
            stack.push(exp[i]);
            continue;
        }
        else if(exp[i] == '*' || exp[i] == '/') {
            while(!stack.empty() && (stack.top() == '/' || stack.top() == '*')) {
                std::string s;
                s = stack.top();
                queue.push(s);
                stack.pop();

            }
            stack.push(exp[i]);
            continue;
        }
    }
    while(!stack.empty()) {
                std::string s;
                s = stack.top();
        queue.push(s);
        stack.pop();
    }

    std::queue<std::string> queue1 = queue;
    std::cout << "postfix: " << std::endl;
    while(!queue1.empty()) {
        std::cout << queue1.front() << " ";
        queue1.pop();
    }
    std::cout << std::endl;
    tree(queue);
}


// Combine tree
void tree(std::queue<std::string> queue) {
    std::stack<Node*> st;
   Node* root;
    while(!queue.empty()) {
        if(isdigit(queue.front()[0])) {
            Node* ptr = createRoot(queue.front());
            st.push(ptr);
            queue.pop();
        }
        else {
            Node* r = st.top(); st.pop();
            Node* l = st.top(); st.pop();
            root = set_left_right(queue.front(),l , r );
            queue.pop();
            st.push(root);
        }
    }
    printTree(root);
}


//print tree
Node* printTree(Node* root) {
    Node* l;
    Node* r;

    if(root -> left && root -> right) {
        l = printTree(root->left);
        r = printTree(root->right);
        std::cout << "    "<< root -> data << std::endl;
        std::cout << "  /   \\" << std::endl;
        std::cout << l -> data << "       " << r -> data << std::endl;
    }
    std::cout << std::endl;
        return root;
}

