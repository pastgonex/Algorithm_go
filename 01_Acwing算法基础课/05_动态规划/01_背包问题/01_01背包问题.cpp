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
    // i从1~n, j从v[i]~m
    // 第 1 层:
    //      dp[v[i]] = max(dp[v[i]], dp[v[i]-v[i]]+w[i])
    //      dp[1] = max(dp[1], dp[0]+2) =2  //dp[1] 正常
    //                         由于j-v[i]肯定是 < j的， 因此此时的dp[j-v[i]]其实是第i层的dp[j-v[i]]
    //      dp[2] = max(dp[2], dp[2-v[1]]+w[1]) = max(dp[2], dp[1]+2)= 4
    //      dp[3] = max(dp[3], dp[3-v[1]]+w[1]) = max(dp[3], dp[2]+2)= 6
    //      dp[m] = max(dp[m], dp[m-v[1]]+w[1])

    // 倒序枚举:
    // i从1~n， j从m~v[i]
    // 第一层：
    //      dp[m] = max(dp[m], dp[m-v[i]]+w[i])
    //      dp[m] = max(dp[m], dp[m-1]+2) =2
    //     dp[m-1]= max(dp[m-1],dp[m-2]+2)=2
    //     dp[v[i]]=max(dp[v[i]-1], dp[v[i]-v[i]]+2) = max(dp[0], dp[0]+2)=2
    // 第二层：
    //      dp[m-1-v[i]]肯定<m, 又因为是倒序枚举的， 因此小的还没有被更新过， 还是第1层时候的m-1-v[i], 与状态转移方程相符
    //      dp[m-1]=max(dp[m-1],dp[m-1-v[i]]+w[i])
    //

    /*
        总结：
            1. 使用倒序枚举
            2. dp[j ~ m]处于“第i个阶段”， 也就是已经考虑过放入第i个物品的情况
               dp[0 ~ j-1]处于“第i-1个阶段”， 也就是还没有第i个物品更新。
            3. 随着 j 不断减小， 意味着我们总是用“第 i-1 个阶段”的状态向”第 i 个阶段“的状态进行转移， 符合线性DP的原则
               进而保证了第i个物品只会被放入背包一次。
            
            4. 如果使用正序循环， 假设dp[j] 被 dp[j-v[i]]+w[i]更新， 接下来j增大到j+v[i]时， dp[j+v[i]]又可能被dp[j]+w[i]更新。
               此时， 两个都处于”第i个阶段“的状态之间发生了转移， 违背了线性DP的原则， 相当于第i个物品被使用了两次（加了两次w[i]）。
               因此必须用倒序循环， 才符合 0/1背包问题中每个物品是唯一的、只能放入背包一次的要求。

    */
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
