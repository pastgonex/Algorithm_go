/*
 * Project: 05_Monotonic_Stack
 * File Created:Monday, December 28th 2020, 10:52:22 am
 * Author: Bug-Free
 * Problem:AcWing 830. 单调栈
 */
// brute-force
// for (int i = 1; i < n; i++) {
//     int t = a[i];
//     int j;
//     for (j = i - 1; j >= 0; j--) {
//         if (a[j] < t) {
//             cout << a[j] << " ";
//             break;
//         }
//     }
//     if (j == -1) {
//         cout << -1 << " ";
//     }
#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (!stk.empty() && stk.top() >= x) {
            stk.pop();
        }
        if (!stk.empty()) {
            cout << stk.top() << " ";
        } else {
            cout << -1 << " ";
        }
        stk.push(x);
    }
    return 0;
}
