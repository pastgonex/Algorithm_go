/*
 * Project: 0x17_二叉堆
 * File Created:Thursday, January 14th 2021, 10:33:41 am
 * Author: Bug-Free
 * Problem:AcWing 145. 超市
 */
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e4 + 10;

int n;
pair<int, int> a[N];
priority_queue<int> heap;  //默认大根堆, 因此可以把所有的值都取负

void Supermarket() {
    for (int i = 1; i <=n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (a[i].first == heap.size() && -heap.top() < a[i].second) {
            heap.pop();
            heap.push(-a[i].second);
            continue;
        }
        if (a[i].first > heap.size()) {
            heap.push(-a[i].second);
        }
    }
    int ans = 0;
    while (heap.size()) {
        ans += heap.top();
        heap.pop();
    }
    cout << -ans << endl;
}

int main() {
    while (cin >> n) {
        Supermarket();
    }
    return 0;
}
