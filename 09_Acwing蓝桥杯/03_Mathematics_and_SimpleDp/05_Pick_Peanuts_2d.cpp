//
// Created by Genes on 2020/9/4.
//

#include<iostream>

using namespace std;

const int N = 1e2 + 10;

int n, m;
int t;
int f[N][N], g[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j];
            }
        }
        cout << f[n][m] << endl;
    }
    return 0;
}