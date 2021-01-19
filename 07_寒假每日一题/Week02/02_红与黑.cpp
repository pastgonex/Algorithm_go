/*
 * Project: Week02
 * File Created:Friday, January 15th 2021, 7:51:23 am
 * Author: Bug-Free
 * Problem:AcWing 1113. 红与黑
 */
#include <cstring>
#include <iostream>

using namespace std;

const int N = 2e1 + 5;

char g[N][N];
int n, m;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool st[N][N];
// int ans = 1;

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
        // ans++;
        cnt += dfs(a, b);
    }
    return cnt;
}

int main() {
    while (cin >> m >> n, n || n) {
        for (int i = 0; i < n; i++) {
            cin >> g[i];
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
        // 两种方式都可以
        // dfs(x, y);
        // cout << ans << endl;
        // ans = 1;
        cout << dfs(x, y) << endl;
    }
    return 0;
}
