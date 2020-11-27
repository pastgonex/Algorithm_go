//
// Created by Genes on 2020/11/25.
//
// 最大的和
// 把二维的看成一维

#include<iostream>
#include<climits>

using namespace std;

const int N = 1e2 + 10;

int n;
int g[N][N];
int s[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            s[i][j] = s[i - 1][j] + g[i][j];
        }
    }
    // dp 从一维视角看二维
    int res = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int last = 0; //表示以k结尾的子序列的最大值
            for (int k = 1; k <= n; k++) {
                last = max(last, 0) + s[j][k] - s[i - 1][k]; //如果last<0, 则可以舍去 等价于和0取一个max
                res = max(last, res);
            }
        }
    }
    cout << res << endl;
    return 0;
}