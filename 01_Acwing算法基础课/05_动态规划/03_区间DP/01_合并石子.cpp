#include <iostream>

using namespace std;

const int N = 3e2 + 10;

int n;
int s[N], dp[N][N];  // dp[l][r] 表示这堆石子是由最初的 第l~r堆石子合并而成的。

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i], s[i] += s[i - 1];  // 前缀和
    }

    for (int len = 2; len <= n; len++) {  // 阶段
        for (int i = 1; i + len - 1 <= n; i++) {  // 状态：左端点
            int l = i, r = i + len - 1;  // 状态：右端点
            dp[l][r] = 0x3f3f3f3f;
            for (int k = l; k < r; k++) {  // 决策
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}