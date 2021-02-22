#include <iostream>

using namespace std;

int v[10], head[10], Next[10];
int ver[10];
int d[10];

void dfs(int x)
{
    v[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (v[y]) {
            continue;
        }
        d[y] = d[x] + 1;  // 从父节点x到子节点y递推， 计算深度
        dfs(y);
    }
}
