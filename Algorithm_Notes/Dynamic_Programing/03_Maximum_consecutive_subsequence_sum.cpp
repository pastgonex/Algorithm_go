//
// Created by Genes on 2020/9/6.
//
// dp[i] 表示以 f[i] 作为结尾的连续序列的最大和
// dp[i] = max(f[i],dp[i-1]+a[i])
// 如何设计状态和状态转移方程是动态规划的核心
// 无后效性: 当前状态记录了历史信息, 一但当前状态确定, 就不会发生改变, 且未来的决策只能在一个或若干个
// 状态的基础上进行, 历史信息只能通过已有的状态, 去影响未来的决策

#include<iostream>

using namespace std;

const int N = 1e4 + 10;

int n;
int f[N];
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    // 处理边界
    // 两种情况
    // 1. dp[i] = f[i]
    // 2. dp[i] = dp[i-1] + f[i]
    dp[1] = f[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(f[i], dp[i - 1] + f[i]);
    }
    int k = 1;
    for (int i = 2; i <= n; i++) {
        if (dp[i] > dp[k]) {
            k = i;
        }
    }
    cout << dp[k] << endl;
    return 0;
}