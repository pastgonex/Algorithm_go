#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n, m;
char A[N], B[N];
int dp[N][N];

int main()
{
    cin >> n;
    cin >> (A + 1);
    cin >> m;
    cin >> (B + 1);

    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (A[i] != B[j]));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}