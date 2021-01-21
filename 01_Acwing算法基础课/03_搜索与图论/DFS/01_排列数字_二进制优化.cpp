/*
 * Project: DFS
 * File Created:Wednesday, January 20th 2021, 5:20:22 pm
 * Author: Bug-Free
 * Problem: AcWing 842. 排列数字 二进制优化
 */
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];

void dfs(int u, int state) {
    if (u == n + 1) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                cout << " ";
            }
            cout << path[i];
        }
        puts("");
    }
    for (int i = 1; i <= n; i++) {
        if (!(state >> i & 1)) {
            path[u] = i;
            dfs(u + 1, state + (1 << i));
        }
    }
}

int main() {
    cin >> n;
    dfs(1, 0);
    return 0;
}
