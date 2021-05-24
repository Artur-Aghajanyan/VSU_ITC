#include <iostream>
#include <string>
#include "stack.h"

bool bracket(std::string str) {
    Stack<char> s1;
    int len = str.length();
    for(int i = 0; i < len; ++i) {
        char ch = str.at(i);
        if((ch == '(')||(ch == '{')||(ch == '[')) {
        s1.push(ch);
    }
        if(ch == ')') {
            if(!s1.empty()) {
                if(s1.top() == '(') {
                    s1.pop();
                    continue;
                }
                else return false;
            }
            else return false;
        }
        else if(ch == '}') {
            if(!s1.empty()) {
                if(s1.top() == '{') {
                    s1.pop();
                    continue;
                }
                else return false;
            }
            else return false;
        }
        else if(ch == ']') {
            if(!s1.empty()) {
                if(s1.top() == '[') {
                    s1.pop();
                    continue;
                }
                else return false;
            }
            else return false;
        }
    }
    if(s1.empty()) {
        return true;
    } else return false;
}
