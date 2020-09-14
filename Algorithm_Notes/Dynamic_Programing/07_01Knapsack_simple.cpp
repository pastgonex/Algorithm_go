//
// Created by Genes on 2020/9/8.
//
// 01背包
// 多阶段动态规划问题:
//      有一类动态规划可解的问题, 可以描述成若干个有序的阶段, 且每个阶段的状态只和上一个阶段的状态有关

// dp[i][v] 表示前i件物品恰好装入容量为v的背包中所能获得的最大价值

// 不放第i件物品: dp[i-1][v]
// 放第i件物品: dp[i-1][v-w[i]+c[i]

#include<algorithm>
#include<iostream>

using namespace std;

const int N = 1e3 + 10;

int n, v;
int w[N], dp[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }
    //边界
    for (int i = 0; i <= v; i++) {
        dp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    int max = 0;
    for (int i = 0; i <= v; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    cout << max << endl;
    return 0;

}