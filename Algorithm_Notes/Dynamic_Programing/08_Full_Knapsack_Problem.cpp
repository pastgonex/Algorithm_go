//
// Created by Genes on 2020/9/11.
//
// 完全背包问题
/*有 n 种物品, 每种物品的单件重量为 w[i], 价值为 c[i], 现有一个容量为 V的背包, 问如何选取物品放入背包, 使得背包内物品的总价值最大
其中每种物品都有无穷件*/

//同样令dp[i][v]  表示前i件物品恰好放入容量为v的背包中能获得的最大价值
/*
对第i件物品来说:
    1. 不妨第i件物品, dp[i][v] = dp[i-1][v];
    2. 放第i件物品, dp[i][j] = dp[i][v-w[i]]

    dp[i][v] = max(dp[i][v], dp[i][v-w[i]]+c[i])

    优化成一维, 只和第i层有关, dp[v] = max(dp[v], dp[v-w[i]]+c[i])

    边界, dp[0][v] = 0
*/


#include<iostream>//f[i]表示容量为i的背包所装的物品的最大值

using namespace std;

const int N = 1e3 + 10;

int n, V;
int w[N], c[N];
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> V;//v表示背包的总容量
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];//v[i]示每一个物品的体积,w[i]为价值
    }
    for (int i = 1; i <= n; i++) {//i枚举物品
        for (int j = w[i]; j <= V; j++)//j枚举体积
        {
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
