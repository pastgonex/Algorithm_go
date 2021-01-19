/*
 * Project: Week02
 * File Created:Friday, January 15th 2021, 10:35:46 am
 * Author: Bug-Free
 * Problem:AcWing 680. 剪绳子
 */
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];

bool check(double x) {  //减长度为x的绳子, 看是否可以剪出m根
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] / x;
        if (res >= m) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double l = 0, r = 1e9;
    while (r - l > 1e-4) {
        double mid = l + (r - l) / 2;
        if (check(mid)) {  //若能剪出mid的长度,
                           //则左边一定可以,答案一定在右半边(包括mid)
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(2) << l << endl;
    return 0;
}
