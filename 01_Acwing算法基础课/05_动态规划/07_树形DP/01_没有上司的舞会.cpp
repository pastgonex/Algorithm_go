#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 6e3 + 10;

int n;
int head[N], e[N], ne[N], idx;
int happy[N];
int f[N][2];
bool has_fa[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx++;
}

void dfs(int u)
{
    f[u][1] = happy[u];

    for (int i = head[u]; ~i; i = ne[i]) {
        int j = e[i];

        dfs(j);

        f[u][1] += f[j][0];
        f[u][0] += max(f[j][0], f[j][1]);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> happy[i];
    }

    memset(head, -1, sizeof head);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a);  // b是父节点
        has_fa[a] = true;
    }

    int root = 1;
    while (has_fa[root]) {  // 找到根节点
        root++;
    }

    dfs(root);  //从根节点出发

    cout << max(f[root][0], f[root][1]);

    return 0;
}