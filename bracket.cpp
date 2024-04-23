#include "bracket.h"

bool checkBrackets(const std::string& s) {
    std::stack<char> cont;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{' || c == '<') {
            cont.push(c);
        } else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (cont.empty()) {
                return false;
            }
            char openBracket = cont.top();
            cont.pop();
            if ((c == ')' && openBracket != '(') ||
                (c == ']' && openBracket != '[') ||
                (c == '}' && openBracket != '{') ||
                (c == '>' && openBracket != '<')) {
                return false;
            }
        }
    }

    return cont.empty();
}
