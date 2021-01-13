/*
 * Project: 0x41_并查集
 * File Created:Tuesday, January 13th 2021, 11:36:09 am
 * Author: Bug-Free
 * Problem:AcWing 239. 奇偶游戏
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 2e4 + 10;

int n, m;
int p[N], d[N];
unordered_map<int, int> S;

int get(int x) {
    if (S.count(x) == 0) {
        S[x] = ++n;
    }
    return S[x];
}

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] ^= d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main() {
    cin >> n >> m;
    n = 0;

    for (int i = 0; i < N; i++) {
        p[i] = i;
    }

    int res = m;  //如果无矛盾, 输出问题数量, 初始的时候为m
    for (int i = 1; i <= m; i++) {
        int a, b;
        string type;
        cin >> a >> b >> type;
        a = get(a - 1), b = get(b);  // s[a-1], s[b]

        int t = 0;
        if (type == "odd") {
            t = 1;
        }
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            if ((d[a] ^ d[b]) != t) {
                res = i - 1;
                break;
            }
        } else {
            p[pa] = pb;
            d[pa] = d[a] ^ d[b] ^ t;
        }
    }
    cout << res << endl;
}
