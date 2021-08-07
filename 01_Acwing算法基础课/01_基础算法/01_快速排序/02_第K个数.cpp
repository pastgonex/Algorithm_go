//
// Created by Genes on 2020/11/16.
//
// 第k个数

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int q[N];

int quick_select(int l, int r, int k) {
    if (l >= r) {
        return q[l];
    }
    int x = q[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    // l - j 有 j-l+1个数字
    int sl = j - l + 1;
    if (k <= sl) {
        return quick_select(l, j, k);
    } else {
        return quick_select(j + 1, r, k - sl);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    cout << quick_select(0, n - 1, k) << endl;
    return 0;
}
