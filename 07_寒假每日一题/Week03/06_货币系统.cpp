/*
 * Project: Week03
 * File Created:Saturday, January 23rd 2021, 9:23:50 am
 * Author: Bug-Free
 * Problem:AcWing 1371. 货币系统
 */
#include <iostream>

using namespace std;

const int N = 1e4 + 10;

typedef long long LL;

int n, m;
LL f[N];

int main() {
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        for (int j = v; j <= m; j++) {
            f[j] += f[j - v];
        }
    }
    cout << f[m] << endl;
    return 0;
}
