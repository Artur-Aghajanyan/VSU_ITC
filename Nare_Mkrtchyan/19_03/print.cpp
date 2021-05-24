#include <iostream>
#include "print.h"

int print() {
    static int count = 0;
     return ++count;
}
