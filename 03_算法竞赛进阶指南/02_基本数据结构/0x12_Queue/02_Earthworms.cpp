/*
 * Project: 0x12_Queue
 * File Created:Monday, December 28th 2020, 8:26:16 am
 * Author: Bug-Free
 * Problem: AcWing133. 蚯蚓
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int n, m, q, u, v, t;

queue<int> A, B, C;
int a[N];
int delta;

int get_max() {
    int x = INT_MIN;
    if (!A.empty()) {
        x = max(x, A.front());
    }
    if (!B.empty()) {
        x = max(x, B.front());
    }
    if (!C.empty()) {
        x = max(x, C.front());
    }
    if (!A.empty() && x == A.front()) {
        A.pop();
    } else if (!B.empty() && x == B.front()) {
        B.pop();
    } else {
        C.pop();
    }
    return x;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        A.push(a[i]);
    }
    double p = (double)u / v;
    for (int i = 1; i <= m; i++) {
        int x = get_max();
        x += delta;
        if (i % t == 0) {
            if (i != t) {
                cout << " ";
            }
            cout << x;
        }
        int left = x * 1ll * p;
        int right = x - left;
        delta += q;
        B.push(left - delta);
        C.push(right - delta);
    }
    cout << endl;
    for (int i = 1; i <= n + m; i++) {
        int x = get_max();
        if (i % t == 0) {
            if (i != t) {
                cout << " ";
            }
            cout << x + delta;
        }
    }
    cout << endl;
    return 0;
}
