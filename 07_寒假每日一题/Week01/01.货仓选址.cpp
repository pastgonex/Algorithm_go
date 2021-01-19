/*
 * Project: 07_寒假每日一题
 * File Created:Friday, January 15th 2021, 7:45:11 am
 * Author: Bug-Free
 * Problem: AcWing 104. 货仓选址
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, res;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        res += a[i] - a[i >> 1];
    }
    cout << res << endl;
    return 0;
}
