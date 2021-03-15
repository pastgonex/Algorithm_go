#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 10;

struct Node
{
    int l, r;
    int data;
} tr[N * 4];

void pushup(int u)
{
    tr[u].data = max(tr[u << 1].data, tr[u << 1 | 1].data);
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);  //这里也可以不用, 因为相当于初始化了一个全为0的线段树
}

void change(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].data = v;
    }
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            change(u << 1, x, v);
        }
        else {
            change(u << 1 | 1, x, v);
        }
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].data;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    int v   = 0;
    if (l <= mid) {
        v = query(u << 1, l, r);
    }
    if (r > mid) {
        v = max(v, query(u << 1 | 1, l, r));
    }
    return v;
}

int m, p;

int main()
{
    cin >> m >> p;
    int n = 0, last = 0;
    build(1, 1, m);
    int x;
    char op[2];
    while (m--) {
        cin >> op >> x;
        if (*op == 'Q') {
            last = query(1, n - x + 1, n);
            cout << last << endl;
        }
        else {
            change(1, n + 1, (last + x) % p);
            n++;
        }
    }
    return 0;
}
