#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
int g[N][N];

int gauss()
{
    int r = 0, c;
    for (int c = 0; c < n; c++)  //按列进行枚举
    {
        int t = r;  //找到非0行，用t进行存储
        for (int i = r; i < n; i++)
            if (g[i][c])
                t = i;

        if (!g[t][c])
            continue;  //没有找到1，继续下一层循环

        for (int i = c; i <= n; i++)
            swap(g[r][i], g[t][i]);  //把第r行的数与第t行交换。

        for (int i = r + 1; i < n; i++)  //用r行把下面所有行的当前列消成0
            if (g[i][c])
                for (int j = n; j >= c; j--)
                    g[i][j] ^= g[r][j];
        r++;
    }
    if (r < n) {
        for (int i = r; i < n; i++) {
            if (g[i][n])
                return 2;
        }
        return 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            g[i][n] ^= g[i][j] * g[j][n];
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> g[i][j];
        }
    }

    int t = gauss();
    if (t == 0) {
        for (int i = 0; i < n; i++) {
            cout << g[i][n] << endl;
        }
    }
    else if (t == 1)
        puts("Multiple sets of solutions");
    else
        puts("No solution");
    return 0;
}