#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n, m;
int v[N][N], w[N][N], dp[N];

int main()
{
    cin >> n >> m;

    memset(dp, 0xcf, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            cin >> v[i][j] >> w[i][j];
        }
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= s; k++) {
                if (j >= v[i][k]) {
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}