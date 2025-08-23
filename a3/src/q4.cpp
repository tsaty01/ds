/*
4. Write a program to convert an Infix expression into a Postfix expression.
*/
#include "Stack.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Ref: https://www.slideserve.com/jens/transforming-infix-to-postfix
*/
string infix_to_postfix(const string& expr) {
    Stack<char> postfix_expr, operator_stack;

    const auto is_left_associative = [](char op) -> bool {
        switch (op) {
            case '^': return false;
        }
        return true;
    };

    const auto is_higher_precedence = [&](char top, char newop) -> bool {
        if (top == newop) {
            /*
            Left-associative pops on equal precedence (e.g., seeing * with * on
            stack → pop). Right-associative does NOT pop on equal precedence
            (e.g., seeing ^ with ^ on stack -> do not pop).
            */
            return is_left_associative(newop);
        }
        switch (top) {
            case '(':
            case ')': {
                return false;
            }
            case '^':
            case '/':
            case '*': {
                return true;
            }
            case '+':
            case '-': {
                switch (newop) {
                    case '/':
                    case '*': return false;
                    default : return true;
                }
            }
            default: return true;
        }
    };

    for (const char& ch : expr) {
        switch (ch) {
            case '(': {
                operator_stack.push(ch);
                break;
            }
            case ')': {
                char* op = nullptr;
                while ((op = operator_stack.peek()) && *op != '(') {
                    postfix_expr.push(*op);
                    operator_stack.pop();
                }
                if (op && *op == '(') operator_stack.pop();
                break;
            }
            case '^': {
                operator_stack.push(ch);
                break;
            }
            case '/':
            case '*':
            case '+':
            case '-': {
                char *op, *two = nullptr;
                while ((op = operator_stack.peek())
                       && is_higher_precedence(*op, ch)) {
                    postfix_expr.push(*op);
                    operator_stack.pop();
                }
                operator_stack.push(ch);
                break;
            }
            case ' ': break;
            default : postfix_expr.push(ch); break;
        }
    }
    if (!operator_stack.isEmpty()) {
        postfix_expr.push(*operator_stack.peek());
        operator_stack.pop();
    }
    return postfix_expr.to_string();
}

void q4() {
    cout << "Converting an Infix expression into a Postfix expression.\n";
    vector<string> exprs = {
        "(A+B)",
        "(A+B) / (C-D) - (E * F)",
        "A / (B * ( C + ( D - E ) ))",
        "(A+B) * (C-D) / (E-F)",
        "(A+B) * ((C-D) / (E-F))",
        "(7^l^1-(8*d/i))",
        "(7*l*1-(8*d/i))",
    };

    for (const auto& expr : exprs) {
        // cout << expr << '\n';
        cout << infix_to_postfix(expr) << '\n';
    }
}
