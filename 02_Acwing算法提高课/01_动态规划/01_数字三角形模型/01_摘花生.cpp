#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int t;
int a[N][N], dp[N][N];
int r, c;

int main()
{
    cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> a[i][j];
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
        cout << dp[r][c] << endl;
    }
    return 0;
}
