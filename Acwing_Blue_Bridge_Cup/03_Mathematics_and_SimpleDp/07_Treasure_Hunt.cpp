//
// Created by Genes on 2020/9/11.
//
//  地宫寻宝
//  第一个要想清楚的就是，要取得当前格子的物品，这个物品必须比当前所拥有的物品都大，所以有一个性质:
//  后面拿的物品比前面的物品大

//
#include<iostream>

using namespace std;

const int N = 5e1 + 5;
const int M = 1e1 + 5;
const int MOD = 1e9 + 7;

int n, m, c;
int a[N][N];

int dp[N][N][M][M];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j]++; //进行一个偏移
        }
    }
    //两个边界初始化
    //在起点(1,1) 处
    // 如果拿也只能拿a[i][j]这个物品, 只有一种方案
    // 如果不拿, 那就是0个物品, 也是一个方案数
    // 由于物品价值已经增加了一个偏移量, 现在价值的范围是[1,13]
    // 所有价值为0并不代表物品的价值,  而是一个边界点
    dp[1][1][0][0] = 1;
    dp[1][1][1][a[1][1]] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int cnt = 0; cnt <= c; cnt++) {
                for (int k = 0; k < M; k++) {
                    //不拿物品
                    dp[i][j][cnt][k] = (dp[i][j][cnt][k] + dp[i - 1][j][cnt][k]) % MOD;
                    dp[i][j][cnt][k] = (dp[i][j][cnt][k] + dp[i][j - 1][cnt][k]) % MOD;

                    // 可以拿
                    if (cnt > 0 && k == a[i][j]) {
                        for (int s = 0; s < a[i][j]; s++) {
                            dp[i][j][cnt][k] = (dp[i][j][cnt][k] + dp[i - 1][j][cnt - 1][s]) % MOD;
                            dp[i][j][cnt][k] = (dp[i][j][cnt][k] + dp[i][j - 1][cnt - 1][s]) % MOD;

                        }
                    }
                }
            }
        }
    }
    //最后把在终点(n,m)处拿c个物品的方案数累加
    int res = 0;
    for (int i = 1; i < M; i++) {
        res = (res + dp[n][m][c][i]) % MOD;
    }
    cout << res << endl;
    return 0;
}