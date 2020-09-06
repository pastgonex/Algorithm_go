// f[n][m]存的是 第n层第j个数字
// 第n层有n个节点
// dp[i][j] 表示从第i行第j个数字出发, 到底层的所有路径中的最大值
// dp[1][1] = max(dp[2][1],dp[2][2])+f[1][1]
// dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+f[i][j]
// 一个问题必须拥有最有子结构, 才可以使用动态规划来求解

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e1;

int f[N][N];
int n;
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }

    // 处理一下边界
    for (int j = 1; j <= n; j++) {
        dp[n][j] = f[n][j];
    }

    // 从n-1层不断往上, 计算出dp[i][j]
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}