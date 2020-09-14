//
// Created by Genes on 2020/9/7.
//

// 最长公共子序列 LCS

// dp[i][j] 表示所有的 a[1-i] 与 b[1-j] 的公共子序列的集合
// 属性是Max 最大值
// 状态计算:
// 1. a[i] b[j] 都不包含
// 2. 包含a[i], 不包含b[j]
// 3. 不包含a[i], 包含b[j]
// 4. a[i] b[j] 都包含
// 不重不漏

// 算法笔记的思路
// dp[i][j] 表示所有的 a[1-i] 与 b[1-j] 的公共子序列的集合
// a[i]!=b[j]   ---> dp[i-1][j-1]+1
// a[i]==b[j]   ---> max(dp[i-1][j], dp[i][j-1])
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int n, m;
int dp[N][N];
char a[N];
char b[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    // 这里要处理边界, 但是是全局数组, 所以不需要
//    for (int i = 1; i <= n; i++) {
//        dp[i][0] = 0;
//    }
//
//    for (int j = 1; j <= m; j++) {
//        dp[0][j] = 0;
//    }

    cin >> (a + 1) >> (b + 1); //下标从1开始为好
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

