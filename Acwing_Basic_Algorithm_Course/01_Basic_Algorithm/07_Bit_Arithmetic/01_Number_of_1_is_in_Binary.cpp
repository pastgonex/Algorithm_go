//
// Created by Genes on 2020/12/7.
//
// 二进制中1个个数
#include <iostream>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int lowbit(int x) {
    return x & (-x);
}

int main() {
    ios;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int ans = 0;
        while (a[i]) {
            a[i] -= lowbit(a[i]);
            ans++;
        }
        if (i > 0) {
            cout << " ";
        }
        cout << ans;
    }
    return 0;
}