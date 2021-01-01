/*
 * Project: 0x12_Queue
 * File Created:Friday, January 1st 2021, 3:09:06 pm
 * Author: Bug-Free
 * Problem:AcWing135. 最大子序和
 */

// Brute-force 暴力

// #include <algorithm>
// #include <iostream>

// using namespace std;

// const int N = 3e5 + 10;

// int a[N];

// typedef long long ll;

// ll res = 0;
// int n, m;

// int main() {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < i + m && j < n; j++) {
//             ll sum = 0;
//             for (int k = i; k <= j; k++) {
//                 sum += a[k];
//             }
//             res = max(res, sum);
//         }
//     }
//     cout << res << endl;
//     return 0;
// }
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>

using namespace std;

const int N = 3e5 + 10;

typedef long long ll;

int n, m;
deque<int> q;

ll s[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    ll res = INT_MIN;
    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (!q.empty() && i - q.front() > m) {
            q.pop_front();
        }
        res = max(res, s[i] - s[q.front()]);
        while (!q.empty() && s[q.back()] >= s[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << res << endl;
    return 0;
}
