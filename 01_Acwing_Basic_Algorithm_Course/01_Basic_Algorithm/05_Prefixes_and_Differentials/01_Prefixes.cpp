//
// Created by Genes on 2020/11/30.
//
// 前缀和
#include <iostream>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e5 + 10;

int a[N], s[N];
int n, m;

int main() {
    ios;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) { //注意, 前缀和与差分的下标从1开始
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl; //公式
    }
    return 0;
}