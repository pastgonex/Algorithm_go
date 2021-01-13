/*
 * Project: 06_Monotonic_Queue
 * File Created:Thursday, December 31st 2020, 8:11:16 pm
 * Author: Bug-Free
 * Problem:AcWing154. 滑动窗口
 */
// brute-force
// #include <climits>
// #include <iostream>

// using namespace std;

// const int N = 1e6 + 10;

// int n, k;
// int a[N];

// int main() {
//     cin >> n >> k;

//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     for (int i = 0; i <= n - k; i++) {
//         int minn = INT_MAX;
//         for (int j = i; j < i + k; j++) {
//             minn = min(minn, a[j]);
//         }
//         cout << minn << " ";
//     }
//     cout << endl;
//     for (int i = 0; i <= n - k; i++) {
//         int maxn = INT_MIN;
//         for (int j = i; j < i + k; j++) {
//             maxn = max(maxn, a[j]);
//         }
//         cout << maxn << " ";
//     }
//     cout << endl;
//     return 0;
// }

// 单调队列
#include <deque>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, k;
deque<int> q;
int a[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 维护窗口最小值
    for (int i = 0; i < n; i++) {
        // 判断是否已经滑出窗口
        if (!q.empty() && i - k + 1 > q.front()) {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k - 1) {
            cout << a[q.front()] << " ";
        }
    }
    cout << endl;
    // 维护窗口最大值
    // q.clear();
    for (int i = 0; i < n; i++) {
        // 判断是否已经滑出窗口
        if (!q.empty() && i - k + 1 > q.front()) {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] <= a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k - 1) {
            cout << a[q.front()] << " ";
        }
    }
    cout << endl;
    return 0;
}
// 1 3 -1 -3 5 3 6 7
// -1 -3 -3 -3 5 3
