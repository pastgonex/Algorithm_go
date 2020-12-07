//
// Created by Genes on 2020/11/30.
//
// 二维前缀和
// 子矩阵的和
#include <iostream>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e3 + 10;

int a[N][N], s[N][N];
int n, m, q;

inline int solve(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]; //公式, 画图即可
}

int main() {
    ios;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) { // 前缀和和差分下标都从1开始
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]; //初始化二维前缀和数组
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << solve(x1, y1, x2, y2) << endl;
    }
    return 0;
}
