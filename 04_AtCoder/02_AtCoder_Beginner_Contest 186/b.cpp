/*
 * Project: 02_AtCoder_Beginner_Contest 186
 * File Created:Monday, January 4th 2021, 5:14:29 pm
 * Author: Bug-Free
 * Problem: B - Blocks on Grid
 */
// 策略
// 最后要所有的相同, 这取决于最小的
// 找到最小的数minx, 然后sum+=(所有的数字-minx)

#include <climits>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int h, w;
int g[N][N];

int main() {
    cin >> h >> w;
    int minx = INT_MAX;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
            minx = min(minx, g[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            sum += g[i][j] - minx;
        }
    }
    cout << sum << endl;
    return 0;
}
