/*
 * Project: 0x11_Stack
 * File Created:Thursday, December 31st 2020, 4:22:09 pm
 * Author: Bug-Free
 * Problem:AcWing 131. 直方图中最大的矩形
 */

// Brute-force
// #include <iostream>

// using namespace std;

// const int N = 1e5 + 10;

// int n;
// int res;
// int a[N];

// int main() {
//     while (cin >> n, n) {
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
//         for (int i = 0; i < n; i++) {
//             int cnt1 = 0, cnt2 = 0;
//             int j = i - 1;
//             while (j >= 0 && a[i] <= a[j]) {
//                 j--;
//                 cnt1++;
//             }
//             j = i + 1;
//             while (a[j] >= a[i] && j < n) {
//                 j++;
//                 cnt2++;
//             }
//             res = max(res, (cnt1 + cnt2 + 1) * a[i]);
//         }
//         cout << res << endl;
//     }
//     return 0;
// }

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

int n, h[N], l[N], r[N];

void get(int* last) {
    stack<int> stk;
    h[0] = -1;
    stk.push(0);
    for (int i = 1; i <= n; i++) {
        while (h[stk.top()] >= h[i]) {
            stk.pop();
        }
        last[i] = stk.top() + 1;
        stk.push(i);
    }
}

int main() {
    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        get(l);
        reverse(h + 1, h + n + 1);
        get(r);
        ll res = 0;
        for (int i = 1, j = n; i <= n; i++, j--) {
            // 因为reverse了, 因此现在算的是原本的n-i+1个位置的
            // 此时的l相当于原本的r
            // n-l[j]+1 - r[i]+1
            ll width = (n - l[j] + 1) - r[i] + 1;
            res = max(res, width * h[i]);
        }
        cout << res << endl;
    }
    return 0;
}
