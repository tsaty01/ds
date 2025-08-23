// all answers are written in cpp
// Satyam Tiwari (1024030088)

/*
clang-format off
-----------------------------------------------------------------------------------------------------------------------------------
|                                                       ADDITIONAL QUESTIONS                                                      |
-----------------------------------------------------------------------------------------------------------------------------------
clang-format on
*/

/*
1) Find two numbers in an array whose difference equals K. Given an array
arr[] and a positive integer k, the task is to count all pairs (i, j) such
that i < j and absolute value of (arr[i] - arr[j]) is equal to k.

https://www.geeksforgeeks.org/dsa/count-pairs-difference-equal-k/?utm_source=chatgpt.com#better-approach-sorting-and-two-pointer-technique-onlogn-time-and-o1-space
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*
Sample Inputs:
(4) - 5 1 4 1 4 5 3
(3) - 5 3 2 1 5 4 2
(4) - 4 1 2 2 1 1
*/

int main() {
    vector<int> arr;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the positive integer (k): ";
    cin >> target;

    sort(arr.begin(), arr.end());

    int left  = 0;
    int right = 0;
    n         = arr.size();
    vector<pair<int, int>> targetPairs;

    while (right < n) {
        int val = arr[right] - arr[left];
        if (val == target) {
            targetPairs.emplace_back(left, right);

            int i = left, j = right;

            while (i < n && arr[i] == arr[i + 1]) {
                targetPairs.emplace_back(i + 1, right);
                i++;
            }

            while (j < n && arr[j] == arr[j + 1]) {
                targetPairs.emplace_back(left, j + 1);
                j++;
            }

            if (i == left) left = ++i;
            else left = i;
            if (j == right) right = ++j;
            else right = j;

        } else if (val < target) {
            right++;
        } else if (val > target) {
            left++;
        }
    }

    for (const auto& pair : targetPairs) {
        // Indexes are from sorted array
        printf("[%d, %d]\n", arr[pair.first], arr[pair.second]);
        // printf("[%d, %d]\n", pair.first, pair.second);
    }

    return 0;
}

/*
2) String Split Challenge
You are given a string consisting of lowercase English alphabets. Your task is
to determine if it's possible to split this string into three non-empty parts
(substrings) where one of these parts is a substring of both remaining parts

https://www.codechef.com/practice/course/nutanix-interview-questions/NUTANIXCON01/problems/NUTANIX11?tab=statement
*/
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main() {
    string str;
    cout << "Enter the string to split: ";
    getline(cin, str);

    int n            = str.length();
    const char* data = str.data();

    bool can_split = false;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string_view s1v(data, i);
            string_view s2v(data + i, j - i);
            string_view s3v(data + j, n - j);

            if (s2v.find(s1v) != string::npos
                && s3v.find(s1v) != string::npos) {
                can_split = true;
                cout << s1v << '\n';
                cout << s2v << '\n';
                cout << s3v << '\n';
                cout << '\n';
                break;
            }

            if (s1v.find(s2v) != string::npos
                && s3v.find(s2v) != string::npos) {
                can_split = true;
                cout << s1v << '\n';
                cout << s2v << '\n';
                cout << s3v << '\n';
                cout << '\n';
                break;
            }

            if (s1v.find(s3v) != string::npos
                && s2v.find(s3v) != string::npos) {
                can_split = true;
                cout << s1v << '\n';
                cout << s2v << '\n';
                cout << s3v << '\n';
                cout << '\n';
                break;
            }
        }
        if (can_split) break;
    }

    if (can_split) {
        cout << "The string can be split into 3 parts\n";
    }

    return 0;
}

/*
3) String Anagrams
Given two strings str1 and str2, determine if they form an anagram pair.
Note: Two strings are considered anagrams if one string can be rearranged to
form the other string.

https://www.codechef.com/practice/course/nutanix-interview-questions/NUTANIXCON01/problems/NUTANIX01
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2;

    cout << "Enter string (str1): ";
    getline(cin, str1);

    cout << "Enter string (str2): ";
    getline(cin, str2);

    bool anagrams = false;
    if (str1.size() == str1.size()) {
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 == str2) anagrams = true;
    }

    if (anagrams) {
        cout << "Both strings are anagrams.\n";
    } else {
        cout << "Both strings are not anagrams.\n";
    }

    return 0;
}

/*
4) Sort an array of 0s, 1s and 2s - Dutch National Flag Problem
Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to
sort the array, i.e., put all 0s first, then all 1s and all 2s in last.
https://www.geeksforgeeks.org/dsa/sort-an-array-of-0s-1s-and-2s/
*/
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr;
    arr.resize(n);

    cout << "Enter 0s, 1s or 2s as the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    n = arr.size();

    int low  = 0;
    int mid  = 0;
    int high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[mid], arr[low]);
                mid++;
                low++;
                break;
            case 1: mid++; break;
            case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
            default: cout << "Unexpected element: " << arr[mid]; break;
        }
    }

    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << "\b]\n";

    return 0;
}

/*
5) Given a fixed-length integer array arr, duplicate each occurrence of two
(2), shifting the remaining elements to the right. Note that elements beyond
the length of the original array are not written. Do the above modifications
to the input array in place and do not return anything.
https://leetcode.com/problems/duplicate-zeros/description/
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr;
    arr.resize(n);

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    n = arr.size();

    int target;
    cout << "Enter the element to duplicate: ";
    cin >> target;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            arr.pop_back();
            arr.insert(arr.begin() + i + 1, target);
            i++;
        }
    }

    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << "\b]\n";

    return 0;
}
