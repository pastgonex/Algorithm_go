// #include <iostream>

// using namespace std;

// const int N = 1e3 + 10, mod = 1e9 + 7;

// int n;
// int dp[N][N];

// int main()
// {
//     cin >> n;

//     dp[0][0] = 1;  // 一个数字都不选， 总和为0是一种方案
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= n; j++) {
//             for (int k = 0; k * i <= j; k++) {
//                 dp[i][j] = (dp[i][j] + dp[i - 1][j - k * i]) % mod;
//             }
//         }
//     }
//     cout << dp[n][n];

//     return 0;
// }
// #include <iostream>

// using namespace std;

// const int N = 1e3 + 10, mod = 1e9 + 7;

// int n;
// int dp[N][N];

// int main()
// {
//     cin >> n;

//     dp[0][0] = 1;  // 一个数字都不选， 总和为0是一种方案
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= n; j++) {
//             for (int k = 0; k * i <= j; k++) {
//                 dp[i][j] = (dp[i][j] + dp[i - 1][j - k * i]) % mod;
//             }
//         }
//     }
//     cout << dp[n][n];

//     return 0;
// }
// #include <iostream>

// using namespace std;

// const int N = 1e3 + 10, mod = 1e9 + 7;

// int n;
// int dp[N][N];

// int main()
// {
//     cin >> n;

//     dp[0][0] = 1;

//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= n; j++) {
//             dp[i][j] = dp[i - 1][j];
//             if (j >= i) {
//                 dp[i][j] = (dp[i][j] + dp[i][j - i]) % mod;
//             }
//         }
//     }

//     cout << dp[n][n] << endl;

//     return 0;
// }

// #include <iostream>

// using namespace std;

// const int N = 1e3 + 10, mod = 1e9 + 7;

// int n;
// int dp[N];

// int main()
// {
//     cin >> n;

//     dp[0] = 1;
//     for (int i = 1; i <= n; i++) {
//         for (int j = i; j <= n; j++) {
//             dp[j] = (dp[j] + dp[j - i]) % mod;
//         }
//     }
//     cout << dp[n] << endl;
//     return 0;
// }

#include <iostream>

using namespace std;

const int N = 1e3 + 10, mod = 1e9 + 7;

int n;
int dp[N][N];

int main()
{
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % mod;
        }
    }
    int res = 0;
    for (int i = 0; i <= n; i++) {
        res = (res + dp[n][i]) % mod;
    }
    cout << res << endl;
    return 0;
}