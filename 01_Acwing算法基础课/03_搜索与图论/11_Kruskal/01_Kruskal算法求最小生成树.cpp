#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;

int n, m;
int fa[N];

struct Edge
{
    int a, b, w;

    bool operator<(const Edge& W) const
    {
        return w < W.w;
    }
} edges[M];

int find(int x)
{
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

int kruskal()
{
    sort(edges, edges + m);

    for (int i = 1; i <= n; i++) {
        fa[i] = i;  //初始化并查集
    }

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            fa[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1) {
        return INF;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int t = kruskal();

    if (t == INF) {
        cout << "impossible" << endl;
    }
    else {
        cout << t << endl;
    }
    return 0;
}