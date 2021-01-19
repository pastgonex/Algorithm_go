/*
 * Project: Week01
 * File Created:Friday, January 15th 2021, 3:26:22 pm
 * Author: Bug-Free
 * Problem: AcWing 898. 数字三角形
 */
#include <iostream>

using namespace std;

const int N = 5e2 + 10;

int f[N][N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }
    for (int i = n - 1; i; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
        }
    }
    cout << f[1][1] << endl;
    return 0;
}
