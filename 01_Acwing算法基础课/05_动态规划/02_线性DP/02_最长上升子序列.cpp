// #include <cstring>
// #include <iostream>

// using namespace std;

// const int N = 1e3 + 10;

// int n;
// int a[N], dp[N];

// int main()
// {
//     cin >> n;

//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }

//     memset(dp, 0xcf, sizeof dp);

//     int res = 0;

//     for (int i = 1; i <= n; i++) {
//         dp[i] = 1;
//         for (int j = 0; j < i; j++) {
//             if (a[j] < a[i]) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//         res = max(dp[i], res);
//     }

//     cout << res << endl;

//     return 0;
// }

// 输出最长上升子序列

#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n;
int dp[N], path[N], a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, 0xcf, sizeof dp);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        path[i] = 0;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                }
            }
        }
        res = max(res, dp[i]);
    }

    int k = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[k] < dp[i]) {
            k = i;  // 找到最终状态
        }
    }

    cout << dp[k] << endl;

    for (int i = 0, len = dp[k]; i < len; i++) {
        cout << a[k] << " ";
        k = path[k];
    }
}