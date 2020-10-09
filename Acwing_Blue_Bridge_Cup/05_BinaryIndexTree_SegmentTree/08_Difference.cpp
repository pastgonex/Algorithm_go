//
// Created by Genes on 2020/10/8.
//
// 差分
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

void insert(int l, int r, int x) {
    b[l] += x;
    b[r + 1] -= x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        insert(i, i, a[i]); //构造a的差分数组b
    }
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        insert(l, r, x);
    }
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
        cout << b[i] << " ";
    }
    puts("");
    return 0;
}
