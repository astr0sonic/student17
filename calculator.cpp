#include "calculator.h"

bool isOperator(char oper){
    if(oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == '(' || oper == ')') return true;
    return false;
}

void add_num(const std::string &check, std::string &postfix, int &i){
    bool dot = false;
    while(check[i] >= '0' && check[i] <= '9' || check[i] == '.'){
        if(dot && check[i] == '.') throw std::logic_error("invalid"); // double dot
        if(check[i] == '.') dot = true;
        postfix += check[i++];
    }
    i--;
    postfix += ' ';
}

int priority(char op) {
    if(op == '(' || op == ')')
        return 0;
    else if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

std::string infixtopostfix(std::string check){
    std::stack<double> nums;
    std::stack<char> opers;
    std::string postfix = "";
    int open_brack = 0;
    for(int i = 0; i < check.length(); i ++){
        if(check[i] == ' ') continue;

        else if(check[i] >= '0' && check[i] <= '9' || check[i] == '.'){
            add_num(check, postfix, i);
        }

        else if(check[i] == '('){
            opers.push('(');
            open_brack++;
        }
        else if(check[i] == ')'){
            if(open_brack < 1) throw std::logic_error("invalid");
            while(!opers.empty() && opers.top() != '('){
                postfix += opers.top();
                postfix += ' ';
                opers.pop();
            }
            opers.pop(); // (
            open_brack--;
        }
        else if(isOperator(check[i])){
            if(check[i] == '-' && i + 1 < check.length() - 1 && check[i + 1] >= '0' && check[i + 1] <= '9'){
                    postfix+= '-';
                    i++;
                    add_num(check, postfix, i);
            }
            else{
                while(!opers.empty() && priority(opers.top()) >= priority(check[i])){
                    postfix += opers.top();
                    postfix += ' ';
                    opers.pop();
                }
                opers.push(check[i]);
            }
        }
        if(!(isOperator(check[i]) || (check[i] >= '0' && check[i] <= '9' || check[i] == '.') || check[i] == ' ')){throw std::logic_error("invalid");}
    }
    while(!opers.empty()){
        postfix += opers.top();
        postfix += ' ';
        opers.pop();
    }
    if(open_brack != 0) throw std::logic_error("invalid");
    return postfix;
}



void pochit(std::stack<double> &cont, const char oper){
    double result = 0;
    if(cont.size() < 2) throw std::logic_error("invalid");
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
        case '^': result = pow(second, first);
                break;
    }
    cont.push(result); 
}
double calculatepostfix(const std::string postfix){
    std::stack<double> cont;
    double result = 0;
    for(ptrdiff_t i = 0; i < postfix.length(); i++){
        if(postfix[i] == ' ') continue;
        if(postfix[i] >= '0' && postfix[i] <= '9') {
            std::string num = "";
            while(postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.'){
                num += postfix[i++];    
            }            
            cont.push(std::stod(num));
            }
        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'){pochit(cont, postfix[i]);}
    }
    if(cont.size() != 1) throw std::logic_error("invalid");
    result = cont.top();
    return result;
}

double calculate(const std::string& expr) {
    std::string postfix = infixtopostfix(expr);
    double result = calculatepostfix(postfix);
    return result;
}
