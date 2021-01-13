/*
 * Project: 09_Disjoint_Set
 * File Created:Friday, January 8th 2021, 2:55:49 pm
 * Author: Bug-Free
 * Problem: AcWing 837. 连通块中点的数量
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int fa[N], cnt[N];

int Get(int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = Get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        cnt[i] = 1;
    }

    string op;
    int a, b;
    while (m--) {
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            // if (Get(a) != Get(b)) {
            //     int t= Get(a);
            //     fa[Get(a)] = Get(b);
            //     cnt[Get(b)] += cnt[t];
            // }
            a = Get(a), b = Get(b);
            if (a != b) {
                fa[a] = b;
                cnt[b] += cnt[a];
            }
        } else if (op == "Q1") {
            cin >> a >> b;
            cout << (Get(a) == Get(b) ? "Yes" : "No") << endl;
        } else {
            cin >> a;
            cout << cnt[Get(a)] << endl;
        }
    }
    return 0;
}
