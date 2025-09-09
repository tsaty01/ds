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
    bool balanced = true;
    for (const auto& ch : str) {
        if (!balanced) break;
        switch (ch) {
            case '(':
            case '{':
            case '[': {
                parens.push(ch);
                break;
            }

            case ')': {
                if (parens.isEmpty()) {
                    balanced = false;
                    break;
                }
                char* p = parens.peek();
                if (*p == '(') {
                    parens.pop();
                }
                break;
            }
            case '}': {
                if (parens.isEmpty()) {
                    balanced = false;
                    break;
                }
                char* p = parens.peek();
                if (*p == '{') {
                    parens.pop();
                }
                break;
            }
            case ']': {
                if (parens.isEmpty()) {
                    balanced = false;
                    break;
                }
                char* p = parens.peek();
                if (*p == '[') {
                    parens.pop();
                }
                break;
            }
            default: break;
        }
    }
    cout << (balanced && parens.isEmpty() ? "Balanced" : "Unbalanced") << '\n';
}
