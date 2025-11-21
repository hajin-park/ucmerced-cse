#ifndef RPN_H
#define RPN_H

#include <string>
#include "Stack.h"

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int eval(int x, int y, char op){
    if (op == '+'){
        return x + y;
    }
    else if (op == '-'){
        return x - y;
    }
    else if (op == '*'){
        return x * y;
    }
    else{
        return x / y;
    }
}

int evaluateRPN(std::string expression){
    Stack<int> s;
    std::string curr = "";
    for (int i = 0; i < expression.length(); i++){
        if (expression[i] == ' '){
            if (curr != ""){
                s.push(stoi(curr)); 
                curr = "";
            }
        }
        else{
            if (!isOperator(expression[i])){
                curr += expression[i];
            }
            else{
                int rhs = s.pop();
                int lhs = s.pop();
                s.push(eval(lhs, rhs, expression[i]));
            }
        }
    }

    return s.pop();
}

#endif