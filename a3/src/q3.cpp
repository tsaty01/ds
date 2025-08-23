/*
3. Write a program that checks if an expression has balanced parentheses.
*/
#include "Stack.hpp"

#include <iostream>
#include <string>

using namespace std;

void q3() {
    cout << "Checking parentheses, enter a string with \"(), {}, []\": ";
    string str;
    getline(cin, str);

    Stack<char> parens;
    for (const auto& ch : str) {
        switch (ch) {
            case '(':
            case '{':
            case '[': {
                parens.push(ch);
                break;
            }

            case ')': {
                char* p = parens.peek();
                if (p && *p == '(') {
                    parens.pop();
                }
                break;
            }
            case '}': {
                char* p = parens.peek();
                if (p && *p == '{') {
                    parens.pop();
                }
                break;
            }
            case ']': {
                char* p = parens.peek();
                if (p && *p == '[') {
                    parens.pop();
                }
                break;
            }
            default: break;
        }
    }
    cout << (parens.isEmpty() ? "Balanced" : "Unbalanced") << '\n';
}
