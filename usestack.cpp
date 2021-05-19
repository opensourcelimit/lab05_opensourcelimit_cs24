// usestack.cpp - for CS 24 lab practice using stacks
// NAME(S), DATE

#include "intstack.h"
#include <iostream>
using namespace std;

int main() {
    Stack s;

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
