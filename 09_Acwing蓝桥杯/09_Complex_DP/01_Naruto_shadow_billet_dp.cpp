//
// Created by Genes on 2020/11/13.
//
// 鸣人的影分身 动态规划 dp

// f[i][j] 表示 总和是i, 分为j个数的和的方案

/*
 集合划分:
    1. 最小值是0的集合   --> f[i][j-1]
    2. 最小值不是0的集合:
        可以把每个数字都-1, 那么j个数字总和就减了j
        f[i-j][j]

 状态转移方程 f[i][j] = f[i][j-1]+f[i-j][j]
 */

// f[i][j]= f[i][j-1]+f[i-j][j];

#include<iostream>

using namespace std;

const int N = 1e1 + 1;

int m, n;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        int f[N][N] = {0};
        f[0][0] = 1;//边界  总和是0, 选0个数的方案数是1
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = f[i][j - 1];
                if (i >= j) {
                    f[i][j] += f[i - j][j];
                }
            }
        }
        cout << f[m][n] << endl;
    }
    return 0;
}