/*
5. Write a program for the evaluation of a Postfix expression.
*/
#include "Stack.hpp"

#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int64_t eval_postfix(const vector<string>& expr) {
    int64_t result = 0;
    Stack<int> expr_stack;

    for (const string& token : expr) {
        if (('0' <= token[0] && token[0] <= '9')
            || (token.size() > 1 && token[0] == '-')) {
            expr_stack.push(stoi(token));
            continue;
        }

        if (token.size() == 1) {
            char op = token[0];
            switch (op) {
                case '^':
                case '/':
                case '*':
                case '+':
                case '-': {
                    int rhs = *expr_stack.peek();
                    expr_stack.pop();
                    int lhs = *expr_stack.peek();
                    expr_stack.pop();
                    switch (op) {
                        case '^': expr_stack.push(pow(lhs, rhs)); break;
                        case '/': expr_stack.push(lhs / rhs); break;
                        case '*': expr_stack.push(lhs * rhs); break;
                        case '+': expr_stack.push(lhs + rhs); break;
                        case '-': expr_stack.push(lhs - rhs); break;
                    }
                    break;
                }
            };
        }
    }

    int* val = nullptr;
    while ((val = expr_stack.peek())) {
        result += *val;
        expr_stack.pop();
    }
    return result;
}

void q5() {
    cout << "Evaluating a Postfix expression.\n";
    vector<vector<string>> exprs = {
        {"2", "3", "1", "*", "+", "9", "-"},
        {"100", "200", "+", "2", "/", "5", "*", "7", "+"},
        {"2", "2", "3", "^", "^"},
        {"2", "2", "^", "3", "^"},
    };

    for (const auto& expr : exprs) {
        cout << eval_postfix(expr) << '\n';
    }
}
