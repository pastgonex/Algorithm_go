//
// Created by Genes on 2020/12/8.
//
// 最短Hamilton路径

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 2e1 + 5;

int f[1 << 20][20];
int weight[20][20];


int hamilton(int n, int weight[20][20]) {
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                for (int k = 0; k < n; k++) {
                    if ((i ^ j << j) >> k & 1) {
                        f[i][j] = min(f[i][j], f[i ^ 1 << j][k] + weight[k][j]);
                    }
                }
            }
        }
    }
    return f[(1 << n) - 1][n - 1];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }
    cout << hamilton(n, weight) << endl;
    return 0;
}