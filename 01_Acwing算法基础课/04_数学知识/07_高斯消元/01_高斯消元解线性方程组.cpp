#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss()
{
    int r, c;  // 行，列

    // 枚举每一列
    for (c = 0, r = 0; c < n; c++) {
        // 1. 找出c这一列绝对值最大的数 所在的行
        int t = r;
        for (int i = r; i < n; i++) {  // 这里i枚举的是行
            if (fabs(a[i][c]) > fabs(a[t][c])) {
                t = i;
            }
        }

        // 如果这一列上所有的数都是0的话 , 看下一行
        if (fabs(a[t][c]) < eps) {
            continue;
        }

        // 2. 让第t行与未固定的行(第r行)的第一行交换
        for (int i = c; i < n + 1; i++) {
            swap(a[r][i], a[t][i]);
        }

        // 3. 把这一行第一个非零的数变为1
        // 若从前往后做， 第一次就将a[r][c] 变为1了， 所以倒着做
        for (int i = n; i >= c; i--) {
            a[r][i] /= a[r][c];
        }

        // 4. 将下面所有行的第c列变为0
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > eps) {
                for (int j = n; j >= c; j--) {
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;  // 处理下一行
    }

    // 通过r来观察方程解的数量
    if (r < n) {
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps) {
                return 2;
            }
        }
        return 1;
    }

    // 原方程有n个解
    // 从下往上， 依次求出方程的解
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            a[i][n] -= a[j][n] * a[i][j];
        }
    }

    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> a[i][j];
        }
    }

    int t = gauss();

    if (t == 0) {
        for (int i = 0; i < n; i++) {
            printf("%.2lf\n", a[i][n]);
        }
    }
    else if (t == 1) {
        puts("Infinite group solutions");
    }
    else {
        puts("No solution");
    }
    return 0;
}