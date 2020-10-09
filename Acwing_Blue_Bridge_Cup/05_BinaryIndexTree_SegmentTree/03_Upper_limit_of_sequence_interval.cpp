//
// Created by Genes on 2020/10/6.
//
// 数列区间最大值
// 线段树

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];

struct SegmentTree {
    int l, r;
    int dat;
} t[N * 4];

void pushup(int p) {
    t[p].dat = max(t[p << 1].dat, t[p << 1 | 1].dat); //从下往上传递信息
}

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) {
        t[p].dat = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

int ask(int p, int l, int r) {
    if (l <= t[p].l && r >= t[p].r) {
        return t[p].dat;
    }
    int mid = t[p].l + t[p].r >> 1;
    int val = -(1 << 30);
    if (l <= mid) {
        val = max(val, ask(p << 1, l, r));
    }
    if (r > mid) {
        val = max(val, ask(p << 1 | 1, l, r));
    }
    return val;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    cin >> n >> m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", ask(1, x, y));
    }
    return 0;
}