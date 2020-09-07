//
// Created by Genes on 2020/9/7.
//
// 最长不下降子序列(LIS）

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int n;
int f[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    // 以f[i]结尾的最长不下降子序列
    // 最后是dp[i]
    // dp[i] = max(1 , dp[j]+1)
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1; //默认每个数字自成一个序列
        for (int j = 1; j < i; j++) {
            // >= 连续不下降就行
            if (f[i] >= f[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
