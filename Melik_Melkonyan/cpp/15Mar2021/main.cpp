#include <iostream>
#include "./array.h"

int main() {
    Arr<int>  arr;
    arr.push(4564);
    arr.push(4564);
    arr.print();
    Arr<std :: string> obj;
    obj.push("hello");
    obj.push("hello1");
    obj.push("hello2");
    obj.pop();
    obj.irase(1);
    obj.print();
    return 0;
}