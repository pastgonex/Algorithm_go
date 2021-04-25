#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e1 + 5, M = 1e3 + 10;

int n, m;
char str[M][N];
int dp[N][N];

int edit_distance(char a[], char b[])
{
    int la = strlen(a + 1), lb = strlen(b + 1);
    for (int i = 0; i <= lb; i++) {
        dp[0][i] = i;
    }
    for (int i = 0; i <= la; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    return dp[la][lb];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> (str[i] + 1);
    }

    while (m--) {
        int res = 0;
        char s[N];
        int limit;
        cin >> (s + 1) >> limit;
        for (int i = 0; i < n; i++) {
            if (edit_distance(str[i], s) <= limit) {
                res++;
            }
        }
        cout << res << endl;
    }

    return 0;
}