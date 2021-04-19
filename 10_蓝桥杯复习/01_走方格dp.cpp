#include <iostream>

using namespace std;

const int N = 1e1 + 5;

int n, m;
int dp[N][N];

// dp[i][j]表示从 0，0 走到 i,j 的方案数
// dp[0][1~m] = 1;
// dp[1~n][0] = 1;

int main()
{
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!i || !j) {
                dp[i][j] = 1;
            }
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}