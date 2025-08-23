/*
1. Develop a menu driven program demonstrating the following operations on a
Stack using array: (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v)
display(), and (vi) peek().
*/
#include "Stack.hpp"

#include <iostream>

using namespace std;

void q1() {
    Stack<int> st;

    while (true) {
        cout << R"(---MENU---
1. Push
2. Pop
3. Is empty?
4. Is full?
5. Display
6. Peek/Top
7. Exit
Option: )";

        int opt;
        cin >> opt;

        switch (opt) {
            case 1: {
                int val;
                cout << "Enter value: ";
                cin >> val;
                st.push(val);
                break;
            }
            case 2: {
                cout << "Popping ...\n";
                st.pop();
                break;
            }
            case 3: {
                cout << "Is empty? " << (st.isEmpty() ? "true" : "false")
                     << '\n';
                break;
            }
            case 4: {
                cout << "Is full? " << (st.isFull() ? "true" : "false") << '\n';
                break;
            }
            case 5: {
                cout << "Displaying stack items:\n";
                st.display();
                break;
            }
            case 6: {
                cout << "Top item: " << *st.peek() << '\n';
                break;
            }
            case 7: {
                cout << "Exiting ...\n";
                return;
            }
            default: break;
        }
    }
}
