/*
 * Project: Week02
 * File Created:Friday, January 15th 2021, 8:44:42 am
 * Author: Bug-Free
 * Problem:AcWing 756. 蛇形矩阵
 */
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n, m;
int g[N][N];

// 东-南-西-北-东... (右-下-左-上-右...)
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main() {
    cin >> n >> m;
    //初始从(1,1)开始走, 方向为向东
    int x = 1, y = 1, d = 0;
    for (int i = 1; i <= n * m; i++) {
        int a = x + dx[d], b = y + dy[d];
        if (a < 1 || a > n || b < 1 || b > m || g[a][b]) {
            d = (d + 1) % 4;  //碰壁后转换方向
        }
        g[x][y] = i;
        x += dx[d];
        y += dy[d];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
