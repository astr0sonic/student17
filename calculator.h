#include <string>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>

bool isOperator(char oper);
void add_num(const std::string &check, std::string &postfix, int &i);
int priority(char op);
std::string infixtopostfix(std::string check);
void pochit(std::stack<double> &cont, const char oper);
double calculatepostfix(const std::string postfix);
double calculate(const std::string& expr);
