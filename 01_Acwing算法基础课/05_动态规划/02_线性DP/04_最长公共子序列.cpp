#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int dp[N][N];
char A[N], B[N];

int main()
{
    cin >> n >> m;
    scanf("%s%s", A + 1, B + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (A[i] == B[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}