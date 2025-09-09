#include "Queue.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace extra {

/*
1) Given a function n, write a function that generates and prints all binary
numbers with decimal values from 1 to n. Input: n = 2 Output: 1, 10
https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/
*/

void generate_binary(int n) {
    Queue<string> que(n + 2);
    que.enqueue("1");

    while (n-- > 0) {
        string front = *que.front();
        que.dequeue();
        cout << front;

        que.enqueue(front + "0");
        que.enqueue(front + "1");

        if (n != 0) cout << ", ";
    }
}

void q1() {
    cout << "Generating binary numbers from 1 to n: \n";
    int n = 2;
    cin >> n;
    generate_binary(n);
}

}  // namespace extra
