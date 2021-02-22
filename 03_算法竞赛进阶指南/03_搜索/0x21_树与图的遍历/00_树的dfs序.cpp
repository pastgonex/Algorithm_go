#include <iostream>

using namespace std;

int a[10], head[10], Next[10], ver[10], v[10], m;

void dfs(int x)
{
    a[++m] = x;
    v[x]   = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (v[y]) {
            continue;
        }
        dfs(y);
    }
    a[++m] = x;
}
#
