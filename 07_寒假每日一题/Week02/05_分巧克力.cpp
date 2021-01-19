/*
 * Project: Week02
 * File Created:Friday, January 15th 2021, 11:31:43 am
 * Author: Bug-Free
 * Problem:AcWing 1227. 分巧克力
 */
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int h[N], w[N];

bool check(int mid) {
    int res = 0;  //表示 巧克力数量
    for (int i = 0; i < n; i++) {
        res += (h[i] / mid) * (w[i] / mid);
        if (res >= k)
            return true;  //如果大于k的人了, 说明左边的都是可以的, 因此要让
                          // l=mid;(模板)
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i] >> w[i];
    int l = 1, r = 1e5;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", r);
    return 0;
}
