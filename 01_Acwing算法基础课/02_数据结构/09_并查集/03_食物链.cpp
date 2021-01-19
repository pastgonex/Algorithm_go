/*
 * Project: 09_Disjoint_Set
 * File Created:Friday, January 8th 2021, 4:13:04 pm
 * Author: Bug-Free
 * Problem: AcWing 240. 食物链
 */
#include <iostream>

using namespace std;

const int N = 5e4 + 10;

int n, m;
int fa[N], dist[N];

int find(int x) {
    if (x != fa[x]) {
        int t = find(fa[x]);  //先获取root
        dist[x] += dist[fa[x]];
        fa[x] = t;  //路径压缩
    }
    return fa[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    int res = 0;

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (x > n || y > n) {
            res++;
        } else {
            int fx = find(x), fy = find(y);
            if (op == 1) {
                if (fx == fy && (dist[x] - dist[y]) % 3) {
                    res++;
                } else if (fx != fy) {
                    fa[fx] = fy;
                    dist[fx] = dist[y] - dist[x];
                }
            } else {
                if (fx == fy && (dist[x] - dist[y] - 1) % 3) {
                    res++;
                } else if (fx != fy) {
                    fa[fx] = fy;
                    dist[fx] = dist[y] - dist[x] + 1;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
