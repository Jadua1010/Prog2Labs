//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 1.1
//=====================...........................=================================

#include <iostream>
#include "divide.h"
int main(void) {
    int a = 7;
    int b = 3;
    int c = divide(a, b);
    std :: cout << a << "/" << b << "=" << c << std::endl;
    return 0;
}