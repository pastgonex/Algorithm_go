//
// Created by Genes on 2020/9/4.
//
// 1. 优化的步骤, 先将 第一维删除
// 2.
#include<iostream>

using namespace std;

const int N = 1e3 + 10;
int n, m;
int v[N], w[N];
int f[N];

int main() {

    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j <= m; j++) {
////          f[i][j] = f[i - 1][j];//左边不选择第i个物品的方案
//            f[j] = f[j];
//            if (j >= v[i]) {
////                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//                f[j] = max(f[j], f[j - v[i]] + w[i]);//但是由于是从小到大, 所以这里的f[j-v[i]]肯定先被计算出来了
//            }
//        }
//    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = f[j];//左半边子集
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
//    cout << f[n][m] << endl;
    cout << f[m] << endl;
    return 0;
}