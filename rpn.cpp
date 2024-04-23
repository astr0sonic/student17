#include "rpn.h"

double calculateRPN(const std::string& expr) {
    std::stack<double> cont;
    double result = 0;
    for(ptrdiff_t i = 0; i < expr.length(); i++){
        if(expr[i] == ' ') continue;
        if(expr[i] >= '0' && expr[i] <= '9') {cont.push(static_cast<double>(expr[i] - '0'));}
        else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'){pochit(cont, expr[i]);}
    }
    result = cont.top();
    return result;
}


void pochit(std::stack<double> &cont, const char oper){
    double result = 0;
    double first = cont.top();
    cont.pop();
    double second = cont.top();
    cont.pop();
    switch(oper){
        case '+': result = first + second;
                break;
        case '-': result = second - first;
                break;
        case '*': result = first * second;
                break;
        case '/': result = second / first;
                break;
    }
    cont.push(result); 
}