/*
 * Project: DFS
 * File Created:Wednesday, January 20th 2021, 6:43:58 pm
 * Author: Bug-Free
 * Problem: AcWing 843. n-皇后问题
 */
#include <iostream>

using namespace std;

const int N = 10;

int n;
bool col[N], dg[N * 2], udg[N * 2];
char g[N][N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            puts(g[i]);
        }
        puts("");
        return;
    }
    for (int i = 0; i < n; i++) {
        //只要保证不同对角线会对应到不同数组下标即可
        if (!col[i] && !dg[n - u + i] && !udg[u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[n - u + i] = udg[u + i] = true;
            dfs(u + 1);
            col[i] = dg[n - u + i] = udg[u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }

    dfs(0);

    return 0;
}
