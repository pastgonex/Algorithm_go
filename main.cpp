#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pdd;

#define lc u << 1
#define rc u << 1 | 1
#define mid (t[u].l + t[u].r) / 2
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define mem(a, b) memset(a, b, sizeof(a))
#define FOR(i, x, n) for (int i = x; i <= n; i++)

// const ll mod = 998244353;
// const ll mod = 1e9 + 7;
// const double eps = 1e-6;
// const double PI = acos(-1);
// const double R = 0.57721566490153286060651209;

const int N = 3e5 + 10;

int A[N];

struct Node {
    int l, r;
    int sum;
} t[N << 2];

void push_up(int u) {
    t[u].sum = t[lc].sum ^ t[rc].sum;
}

void build(int u, int l, int r) {
    t[u].l = l;
    t[u].r = r;
    if (l == r) {
        t[u].sum = A[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lc, l, m);
    build(rc, m + 1, r);
    push_up(u);
}

void modify(int u, int p, int v) {
    if (t[u].l == t[u].r) {
        t[u].sum = t[u].sum ^ v;
        return;
    }
    if (p <= mid)
        modify(lc, p, v);
    else
        modify(rc, p, v);
    push_up(u);
}

int query(int u, int ql, int qr) {
    if (ql <= t[u].l && t[u].r <= qr) {
        return t[u].sum;
    }
    int ans = 0;
    if (ql <= mid)
        ans ^= query(lc, ql, qr);
    if (qr > mid)
        ans ^= query(rc, ql, qr);
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    build(1, 1, n);
    while (q--) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1)
            modify(1, x, y);
        else
            cout << query(1, x, y) << endl;
    }
}

signed main() {
    solve();
}
