/*
 * Project: 0x16_Trie
 * File Created:Friday, January 8th 2021, 5:32:55 am
 * Author: Bug-Free
 * Problem:AcWing 144. 最长异或值路径
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
const int SIZE = 3e6 + 10;

int n;
int h[N], e[M], c[M], ne[M], cnt;
int a[N], son[SIZE][2], idx;

void add(int u, int v, int w) {
    e[cnt] = v, c[cnt] = w, ne[cnt] = h[u], h[u] = cnt++;
}

void dfs(int u, int father, int sum) {
    a[u] = sum;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != father) {
            dfs(j, u, sum ^ c[i]);
        }
    }
}

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int& s = son[p][x >> i & 1];
        if (!s) {
            s = ++idx;
        }
        p = s;
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int s = x >> i & 1;
        if (son[p][!s]) {
            res += 1 << i;
            p = son[p][!s];
        } else {
            p = son[p][s];
        }
    }
    return res;
}

int main() {
    memset(h, -1, sizeof h);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    dfs(0, -1, 0);

    for (int i = 0; i < n; i++) {
        insert(a[i]);
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        res = max(res, query(a[i]));
    }

    cout << res << endl;
    return 0;
}
