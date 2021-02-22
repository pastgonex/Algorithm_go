/*
 * Project: 0x41_并查集
 * File Created:Wednesday, January 13th 2021, 12:56:07 pm
 * Author: Bug-Free
 * Problem:AcWing 239. 奇偶游戏
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 2e4 + 10, Base = N / 2;

int n, m;
int p[N], d[N];
unordered_map<int, int> S;

int get(int x)
{
    if (S.count(x) == 0) {
        S[x] = ++n;
    }
    return S[x];
}

int find(int x)
{
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

int main()
{
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
        if (type == "even") {
            if (find(a + Base) == find(b)) {
                res = i - 1;
                break;
            }
            p[find(a)]        = find(b);
            p[find(a + Base)] = find(b + Base);
        }
        else {
            if (find(a) == find(b)) {
                res = i - 1;
                break;
            }
            p[find(a + Base)] = find(b);
            p[find(a)]        = find(b + Base);
        }
    }
    cout << res << endl;
}
