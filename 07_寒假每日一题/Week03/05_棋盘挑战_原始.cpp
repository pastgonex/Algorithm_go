/*
 * Project: Week03
 * File Created:Saturday, January 23rd 2021, 1:06:41 pm
 * Author: Bug-Free
 * Problem:AcWing 1432. 棋盘挑战 原始
 */
#include <iostream>

using namespace std;

const int N = 1e1 + 5;

int n;
int path[N];
bool col[N], row[N], dg[N * 2], udg[N * 2];
int ans;

// 每个位置有两种选择， 放与不放
void dfs(int x, int y, int u) {
    if (u > n) {
        return;
    }
    if (y == n) {
        y = 0, x++;
    }
    if (x == n) {
        if (u == n) {
            ans++;
            if (ans <= 3) {
                for (int i = 0; i < n; i++) {
                    if (i > 0) {
                        cout << " ";
                    }
                    cout << path[i]+1;
                }
                puts("");
            }
        }
        return;
    }
    // 不放的分支
    dfs(x, y + 1, u);

    // 放的分支
    if (!row[x] && !col[y] && !dg[n + y - x] && !udg[x + y]) {
        path[u] = y;
        row[x] = col[y] = dg[n + y - x] = udg[x + y] = true;
        dfs(x, y + 1, u + 1);
        row[x] = col[y] = dg[n + y - x] = udg[x + y] = false;
    }
}

int main() {
    cin >> n;
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}
