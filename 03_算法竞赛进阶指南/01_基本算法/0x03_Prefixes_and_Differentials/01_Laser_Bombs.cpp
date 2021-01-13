//
// Created by Genes on 2020/12/2.
//
// 激光炸弹

#include <algorithm>
#include <iostream>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 5e3 + 10; //不能开 1e5+10, 内存限制比较严格

int s[N][N];
int n, r;

int main() {
    ios;
    cin >> n >> r;
    r = min(5001, r); // 因为r最大可以取 10^9
    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
//        s[++x][++y]=w;  //错误
        s[++x][++y] += w; //右移一位, 就不需要考虑边界了, 并且必须是+=, 不能是=, 因为1个位置可能有多个目标
    }
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
//            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = r; i <= 5001; i++) {
        for (int j = r; j <= 5001; j++) {
            ans = max(ans, s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
        }
    }
    cout << ans << endl;
    return 0;
}