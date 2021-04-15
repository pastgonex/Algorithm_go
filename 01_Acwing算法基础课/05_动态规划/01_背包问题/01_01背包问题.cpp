// 01背包
// 多阶段动态规划问题:
//      有一类动态规划可解的问题, 可以描述成若干个有序的阶段, 且每个阶段的状态只和上一个阶段的状态有关

// dp[i][j] 表示前i件物品恰好装入容量为j的背包中所能获得的最大价值

// 不放第i件物品: dp[i-1][v]
// 放第i件物品: dp[i-1][v-w[i]+c[i]

// 未优化版本
// #include <algorithm>
// #include <iostream>

// using namespace std;

// const int N = 1e3 + 10;

// int n, m;
// int dp[N][N];
// int v[N], w[N];

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
//                 dp[i][j] = max(dp[i - 1][j - v[i]] + w[i], dp[i][j]);
//             }
//         }
//     }

//     cout << dp[n][m] << endl;

//     return 0;
// }

// 优化版本
#include <algorithm>
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

    // 4 5
    // 1 2
    // 2 4
    // 3 4
    // 4 5
    // n=4, m =5
    //    0 1 2 3 4
    // v: 0 1 2 3 4
    // w: 0 2 4 4 5
    // 没有倒序枚举：
    //      dp[v[i]] = max(dp[v[i]], dp[v[i]-v[i]]+w[i])
    //      dp[1] = max(dp[1], dp[0]+2) =2
    //      dp[2] = max(dp[2], dp[2-v[1]]+w[1]) = max(dp[2], dp[1]+2)= 4
    

    for (int i = 1; i <= n; i++) {
        // for(int j = 0;j<=m;j++)
        // for(int j = v[i];j<=m;j++)  j<v[i]是没有意义的， 因此j可以直接从v[i]开始
        for (int j = m; j >= v[i]; j--) {
            // dp[i][j] = dp[i - 1][j];
            // dp[j] = dp[j]; 恒等式，可以直接删除
            // dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            // j-v[i] 是严格小于j的， 因此dp[j-v[i]] 在第i层已经被计算过了，因此dp[j-v[i]]其实是第i层的j-v[i]
            // 上面的等价于dp[j] = max(dp[i][j], dp[i][j - v[i]]+w[i]);
            // 我们需要的是......................dp[i-1][j-v[i]]+w[i]); 不是等价的
            // 我们只需要让j从m开始， 倒着枚举就行了， 此时的dp[j-v[i]] 还没有被更新过， 因此是第i-1层的j-v[i]，和上面等价
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[m] << endl;

    return 0;
}
