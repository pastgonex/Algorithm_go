#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e1 + 5;

int n;
int w[N][N];
int dp[N * 2][N][N];

int main()
{
    scanf("%d", &n);

    int a, b, c;
    while (cin >> a >> b >> c, a || b || c) {
        w[a][b] = c;
    }

    for (int k = 2; k <= n + n; k++) {
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    int t = w[i1][j1];
                    if (i1 != i2) {
                        t += w[i2][j2];
                    }
                    int& x = dp[k][i1][i2];
                    x = max(x, dp[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, dp[k - 1][i1 - 1][i2] + t);
                    x = max(x, dp[k - 1][i1][i2 - 1] + t);
                    x = max(x, dp[k - 1][i1][i2] + t);
                }
            }
        }
    }
    printf("%d\n", dp[n + n][n][n]);

    return 0;
}
