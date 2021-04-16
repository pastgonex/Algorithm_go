/*
    完全背包问题朴素做法
*/
// #include <iostream>

// using namespace std;

// const int N = 1e3 + 10;

// int n, m;
// int dp[N][N], v[N], w[N];

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         cin >> v[i] >> w[i];
//     }
//     for (int i = 1; i <= n; i++) {  // 枚举每一个状态
//         for (int j = 0; j <= m; j++) {  // 总体积不超过j
//             for (int k = 0; v[i] * k <= j; k++) {  //选k件 物品i
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i] * k] + k * w[i]);
//             }
//         }
//     }
//     cout << dp[n][m] << endl;
//     return 0;
// }

// 优化： 三维-> 二维
// #include <iostream>

// using namespace std;

// const int N = 1e3 + 10;

// int n, m;
// int dp[N][N], v[N], w[N];

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         cin >> v[i] >> w[i];
//     }

//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= m; j++) {
//             dp[i][j] = dp[i - 1][j];
//             if (j >= v[i]) {
//                 dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//             }
//         }
//     }

//     cout << dp[n][m] << endl;
//     return 0;
// }

#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int dp[N], v[N], w[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            // dp[i][j] = dp[i - 1][j];
            // dp[j] = dp[j]; 恒等式， 没有意义
            // if (j >= v[i]) 直接从 v[i]开始枚举即可
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);  // 这里的 j-v[i]用的是第i层的，因此可以正序枚举
        }
    }

    cout << dp[m] << endl;
    return 0;
}