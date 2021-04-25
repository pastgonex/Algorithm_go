#include <cstring>
#include <iostream>

using namespace std;

const int N = 20;
const int M = 1 << 20;  // 一共最多有20个1 种状态

int n;
int w[N][N];
int f[M][N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);  //由于要存最小值, 因此初始为正无穷会好一些
    f[1][0] = 0;
    for (int state = 1; state < 1 << n; state++) {  // 从0到111...11 枚举所有state
        if (state & 1) {  // state必须要包含起点1
            for (int j = 0; j < n; j++) {
                if (state >> j & 1) {  // 如果当态前点集包含点j, 那么进行状态转移
                    for (int k = 0; k < n; k++) {
                        if (state ^ (1 << j) >> k & 1) {  //如果从当前状态经过点集state中, 去掉点j后, state 仍然包含点k, 那么才能从点k转移到点j
                            // 当然这个 if 也可以不加，因为如果 state 去掉第 j 个点后，state 不包含点 k 了，
                            // 那么 f[state ^ 1 << j][k] 必然为正无穷，也就必然不会更新 f[state][j]，所以去掉也可以 AC。
                            f[state][j] = min(f[state ^ 1 << j][k] + w[k][j], f[state][j]);
                        }
                    }
                }
            }
        }
    }
    cout << f[(1 << n) - 1][n - 1];  //最后输出 f[111...11][n-1]
    return 0;
}
