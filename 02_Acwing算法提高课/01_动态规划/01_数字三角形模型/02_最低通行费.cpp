#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e2 + 10, INF = 1e9;

int n;
int a[N][N], dp[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i == 1 && j == 1) {
                dp[i][j] = a[i][j];
            }
            else {
                dp[i][j] = INF;
                if (i > 1) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);
                }
                if (j > 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j]);
                }
            }
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}