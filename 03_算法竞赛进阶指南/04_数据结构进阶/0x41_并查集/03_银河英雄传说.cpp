/*
 * Project: 0x41_并查集
 * File Created:Monday, January 11th 2021, 9:35:37 pm
 * Author: Bug-Free
 * Problem: AcWing 238. 银河英雄传说
 */
#include <cmath>
#include <iostream>

using namespace std;

const int N = 3e4 + 10;

int fa[N], d[N], SIZE[N];

int get(int x) {
    if (x == fa[x]) {
        return x;
    }
    int root = get(fa[x]);  //先把get(fa[x])存下来
    d[x] += d[fa[x]];
    return fa[x] = root;  //路径压缩
}

void merge(int x, int y) {
    x = get(x), y = get(y);
    fa[x] = y, d[x] = SIZE[y];
    SIZE[y] += SIZE[x];
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= N; i++) {
        fa[i] = i;
        SIZE[i] = 1;
    }

    while (T--) {
        char op[2];
        int x, y;
        cin >> op >> x >> y;
        if (*op == 'M') {
            merge(x, y);
        } else {
            if (get(x) == get(y)) {
                cout << abs(d[x] - d[y]) - 1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
