/*
 * Project: 02_AtCoder_Beginner_Contest 186
 * File Created:Monday, January 4th 2021, 5:46:07 pm
 * Author: Bug-Free
 * Problem:D - Sum of difference
 */

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int N = 2e5 + 10;

typedef long long ll;

int n;
ll a[N], s[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    ll sum = 0;

    for (int i = 1; i <= n - 1; i++) {
        // for (int j = i + 1; j <= n; j++) {
        //     sum += abs(a[i] - a[j]);
        // }
        // 优化
        sum += s[n] - s[i] - (n - i) * a[i];
    }

    cout << sum << endl;
    return 0;
}
