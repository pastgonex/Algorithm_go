//
// Created by Genes on 2020/12/1.
//
// 一维差分
#include <iostream>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

int main() {
    ios;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - a[i - 1];
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + b[i];
        if (i > 1) {
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;
    return 0;
}


