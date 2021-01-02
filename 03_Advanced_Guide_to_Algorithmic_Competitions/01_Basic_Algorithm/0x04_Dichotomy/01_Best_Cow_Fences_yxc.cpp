//
// Created by Genes on 2020/11/24.
//
// 最佳牛围栏
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, f;
double a[N], s[N];

bool check(double avg) {
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i] - avg; //每个数减一个avg, 如果这一段和>0就说明 原和>=avg
    }
    double mins = 0;
    for (int k = f; k <= n; k++) {
        mins = min(mins, s[k - f]);
        if (s[k] >= mins) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> f;
    double l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r = max(r, a[i]); //右端点
    }
    while (r - l > 1e-5) {//保留三位小数, 就+2=5
        double mid = (l + r) / 2; //平均值
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << int(r * 1000) << endl; //这里只能是r, 虽然l,r很接近, 但还是有差距
    return 0;
}
