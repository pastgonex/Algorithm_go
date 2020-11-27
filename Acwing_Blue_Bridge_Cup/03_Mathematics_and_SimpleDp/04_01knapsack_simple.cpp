//
// Created by Genes on 2020/9/3.
//

//每件物品要么选, 要么不选, 最多只有 2^n种方案, 从这些方案中, 找出总价值最大的方案
//有限集合的最值问题, 就可以使用闫氏dp分析法

#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
const int N = 1e3 + 10;
int v[N], w[N];
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}