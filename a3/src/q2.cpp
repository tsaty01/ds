/*
2. Given a string, reverse it using STACK. For example “DataStructure” should be
output as “erutcurtSataD.”
*/
#include "Stack.hpp"

#include <iostream>

using namespace std;

void q2() {
    Stack<char> st = "DataStructure";
    st.display();
    cout << "Reversing the stack:\n";
    st.reverse();
    st.display();
}
