#include "Stack.hpp"

#include <climits>

using namespace std;

namespace extra {

/*
Design a stack that supports getMin() in O(1) time and O(1) extra space.
https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
*/

class MinStack : public Stack<int> {
    int min = INT_MIN;

public:
    using Stack<int>::Stack;

    MinStack(std::initializer_list<int> init) : Stack<int>(init.size()) {
        for (auto& item : init) {
            push(item);
        }
    }

    void push(int item) {
        if (isEmpty()) {
            Stack::push(item);
            min = item;
            return;
        }

        if (min <= item) {
            Stack::push(item);
        } else {
            Stack::push(2 * item - min);
            min = item;
        }
    }

    void pop() {
        int* top = Stack::peek();
        if (top && min > *top) {
            int prev_min = 2 * min - (*top);
            min          = prev_min;
        }
        Stack::pop();
    }

    int peek() {
        int top = -1;
        if (!isEmpty()) {
            top = *Stack::peek();
            return (min > top) ? min : top;
        }
        return top;
    }

    int getMin() { return isEmpty() ? -1 : min; }
};

void q2() {
    MinStack st;

    st.push(18);
    cout << "Pushed: 18\n";
    cout << "Min: " << st.getMin() << '\n';

    st.push(19);
    cout << "Pushed: 19\n";
    cout << "Min: " << st.getMin() << '\n';

    st.push(29);
    cout << "Pushed: 29\n";
    cout << "Min: " << st.getMin() << '\n';

    st.push(15);
    cout << "Pushed: 15\n";
    cout << "Min: " << st.getMin() << '\n';

    st.push(16);
    cout << "Pushed: 16\n";
    cout << "Min: " << st.getMin() << '\n';

    st.pop();
    cout << "Popped: 16\n";
    cout << "Min: " << st.getMin() << '\n';

    st.pop();
    cout << "Popped: 15\n";
    cout << "Min: " << st.getMin() << '\n';

    st.pop();
    cout << "Popped: 29\n";
    cout << "Min: " << st.getMin() << '\n';
}

}  // namespace extra
