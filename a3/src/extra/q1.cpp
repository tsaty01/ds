#include "Stack.hpp"

#include <vector>

using namespace std;

namespace extra {

/*
Given an array A, find the nearest smaller element for every element A[i] in the
array such that the element has an index smaller than i.
https://www.interviewbit.com/problems/nearest-smaller-element/
*/
static int* prevSmaller(int* A, int n1, int* len1) {
    int* B = new int[n1];
    *len1  = n1;
    Stack<int> small;
    for (int i = 0; i < n1; ++i) {
        if (small.isEmpty()) {
            B[i] = -1;
            small.push(A[i]);
            continue;
        }

        int* top = small.peek();
        if (*top < A[i]) {
            B[i] = *top;
            small.push(A[i]);
        } else {
            while ((top = small.peek()) && *top > A[i]) {
                small.pop();
            }
            if (!small.isEmpty()) {
                B[i] = *small.peek();
            } else {
                B[i] = -1;
                small.push(A[i]);
            }
        }
    }
    return B;
}

void q1() {
    vector<int> A = {2, 5, 1, 4, 8, 3, 2, 5};
    int Blen      = 0;
    int* B        = prevSmaller(A.data(), A.size(), &Blen);

    for (int i = 0; i < Blen; ++i) {
        cout << B[i] << ' ';
    }
    cout << '\n';

    delete[] B;
}

}  // namespace extra
