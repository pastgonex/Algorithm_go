#include <cstring>
#include <iostream>

using namespace std;

const int N = 12, M = 1 << N;

typedef long long ll;

// dp[i][j] 表示前i-1列的方案数已经确定， 并且从第i-1列伸出到第 i列的状态为j的所有方案。
ll dp[N][M];
bool st[M];

int n, m;

int main()
{
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < 1 << n; i++) {
            /*
            第i-2列伸到 i-1 列的状态为 k，
            能成功转移到
            第i-1列伸到 i 列的状态为 j
            */
            st[i] = true;

            // 记录一列中0的个数
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // 判断i状态下， 第j行是否放置方格
                if (i >> j & 1) {  // 1表示放置了方块
                    // 如果放置小方块使得连续的空白格子数成为奇数，
                    // 这样的状态不行， 标记为false
                    if (cnt & 1) {
                        st[i] = false;
                        break;
                    }
                }
                else {
                    cnt++;
                    // 不放置小方格， 空白++
                }
            }
            if (cnt & 1) {  // 判断一下最后一行
                st[i] = false;
            }
        }

        memset(dp, 0, sizeof dp);

        /*
            棋盘从第0列开始， 没有-1列， 所以第0列， 不会有延伸出来的小方块
            没有横着摆放的小方块， 所有小方块都是竖着摆放的， 这种状态记录为一种方案
        */
        dp[0][0] = 1;

        // 把每一列作为阶段
        for (int i = 1; i <= m; i++) {  //阶段
            for (int j = 0; j < 1 << n; j++) {  //枚举i列每一种状态
                for (int k = 0; k < 1 << n; k++) {  // 枚举i-1列每一种状态
                    // dp[i-1][k] 成功转移到 dp[i][j]
                    // st[j | k] == true 表示 在 i 列状态 j， i - 1 列状态 k 的情况下是合法的.
                    // j 表示 前i-1列已经放好， 伸出到第i列的 状态
                    // k 表示 前i-2列已经放好， 伸出到第i-1列的状态
                    // i-2  i-1  i
                    //     ||||||||
                    // ||||||||
                    // j | k = 11 ,然后判断该状态是否合法
                    if ((j & k) == 0 && st[j | k]) {  // j|k 表示第i-1列的状态
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}
