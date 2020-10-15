//
// Created by Genes on 2020/10/12.
//
// 红与黑
// 需要注意, n是列, m是行

#include<iostream>
#include<cstring>

using namespace std;

const int N = 2e1 + 5;

int n, m;
char g[N][N];
bool st[N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int ans = 1;

int dfs(int x, int y) {
    int cnt = 1;
    st[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) {
            continue;
        }
        if (g[a][b] != '.') {
            continue;
        }
        if (st[a][b]) {
            continue;
        }
        cnt += dfs(a, b);
//        ans++;
    }
    return cnt;
}

int main() {
    while (cin >> m >> n, n || m) { //多组数组  先读入 列, 再读入行
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }
        int x, y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '@') {
                    x = i, y = j;
                    break;
                }
            }
        }
        memset(st, false, sizeof st);
        printf("%d\n", dfs(x, y));
//        dfs(x, y);
//        printf("%d\n", ans);
//        ans = 1;
    }
    return 0;
}