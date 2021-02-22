#include <iostream>

using namespace std;

int v[10], head[10], Next[10], ver[10], cnt;
int n;

void dfs(int x)
{
    v[x] = cnt;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (v[y]) {
            continue;
        }
        dfs(y);
    }
}

int main()
{
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            cnt++;
            dfs(i);
        }
    }
}
