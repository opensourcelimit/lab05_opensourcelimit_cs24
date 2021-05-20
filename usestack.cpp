// usestack.cpp - for CS 24 lab practice using stacks
// Jorge Medina 5/19/2021

#include "intstack.h"
#include <iostream>
#include <cstdlib>   // for atof function
#include <cstdio>    // for sscanf
#include <cstring>   // for strcmp and strtok
#include <stack>     // STL stack class
#include <string>    // for throwing string exceptions
using namespace std;

// constants used to identify a token - DO NOT CHANGE
enum TokenType {LEFT, RIGHT, ADD, SUBTRACT, MULTIPLY,
                DIVIDE, NUMBER, OTHER};
TokenType identify(char *t);

TokenType identify(char *t) {
    if (strcmp(t, "+") == 0)
        return ADD;
    if (strcmp(t, "-") == 0)
        return SUBTRACT;
    if (strcmp(t, "*") == 0)
        return MULTIPLY;
    if (strcmp(t, "/") == 0)
        return DIVIDE;
    float value;
    if (sscanf(t, "%g", &value) == 1)
        return NUMBER;
    return OTHER;
}

bool  setLeftRight(int &left, int &right, Stack &s)
{   if( s.empty()) {return false;}
    left = s.top();
     s.pop();
    
    if(s.empty()) {return false;}

    right = s.top();
    s.pop();

    return true;
}



double postFix(char* tokens[], int count){//possibly use token[]
    int left(0), right(0);
    Stack s;
    for(int i = 0; i < count; i++)
    {
        switch( identify( tokens[i])) 
        {   
            case NUMBER: 
                s.push( atoi(tokens[i]));
                break;
            case ADD:
                left = s.top(); 
                s.pop();
                right = s.top();
                s.pop();
               
                
                s.push(left + right);
                break;

            case SUBTRACT:
                left = s.top();
                s.pop();
                right = s.top();
                s.pop();

                s.push( left - right);
                break;

             case MULTIPLY:
                left = s.top();
                s.pop();
                right = s.top();
                s.pop();
                


                s.push(left * right);
                break;

             case DIVIDE:
                left = s.top();
                s.pop();
                right = s.top();
                s.pop();
                
                s.push(left / right);
                break;
              case OTHER:
             
            }
    }
    return s.top();


}







int main() {
   
   char  input[50], *tokens[25];
   int count = 0;

    cout << "enter expression: ";
    cin.getline(input, 50);
     //sample 7 5 3 * +
    char *ptr = strtok(input, " ");
    //takes separate tokens from input and stores them in the tokens char* array
    //each loop raises count by 1 producing the total count of seperate tokens stored in tokens arrayt
    
    while (ptr != 0) {
        tokens[count] = ptr;
        ++count;
        ptr = strtok(0, " ");
    }
    
   cout << "\n" << postFix(tokens, count); 
    
    return 0;
}
