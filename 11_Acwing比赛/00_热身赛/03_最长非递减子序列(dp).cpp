/*
 f[i][j] 表示只考虑 a1∼ai的好子序列，且好子序列的最后一个数在第 j 部分的子序列集合。
*/
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1000005;

int n, x, res;
int f[N][5];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        f[i][1] = f[i - 1][1] + (x == 1);
        f[i][2] = max(f[i - 1][1], f[i - 1][2]) + (x == 2);
        f[i][3] = max(f[i - 1][2], f[i - 1][3]) + (x == 1);
        f[i][4] = max(f[i - 1][3], f[i - 1][4]) + (x == 2);
    }
    for (int i = 1; i <= 4; ++i)
        res = max(res, f[n][i]);
    printf("%d\n", res);
    return 0;
}