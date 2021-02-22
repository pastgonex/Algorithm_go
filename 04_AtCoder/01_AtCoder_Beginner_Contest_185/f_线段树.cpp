#include <iostream>
#include <vector>

using namespace std;

const int N = 3e5 + 10;

int n, q;

struct Node
{
    int l, r;
    int data;
} tr[N << 4];

vector<int> a(N);

void pushup(int u)
{
    tr[u].data = tr[u << 1].data ^ tr[u << 1 | 1].data;
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    if (l == r) {
        tr[u].data = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);  //这里也可以不用, 因为相当于初始化了一个全为0的线段树
}

void change(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].data ^= v;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (x <= mid) {
        change(u << 1, x, v);
    }
    else {
        change(u << 1 | 1, x, v);
    }
    pushup(u);
}

int query(int u, int l, int r)
{
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].data;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    int v   = 0;
    if (l <= mid) {
        v ^= query(u << 1, l, r);
    }
    if (r > mid) {
        v ^= query(u << 1 | 1, l, r);
    }
    return v;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            change(1, x, y);
        }
        else {
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}
