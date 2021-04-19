//
// Created by Genes on 2020/10/16.
//
// 糖果传递
// 贪心
// 排序

/*
 * ans=|X1| + |X2| + |X3| + ……+ |Xn|。
 * 我们希望Xi的绝对值之和尽量小，即|X1| + |X1-C1| + |X1-C2| + ……+ |X1-Cn-1|要尽量小。
 * 注意到|X1-Ci|的几何意义是数轴上的点X1到Ci的距离，所以问题变成了：给定数轴上的n个点，找出一个到他们的距离之和尽量小的点，而这个点就是这些数中的中位数
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1000010;

int n;
int a[N];
LL c[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    LL sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];

    LL avg = sum / n;
    for (int i = n; i > 1; i--) {
        c[i] = c[i + 1] + avg - a[i];
    }
    c[1] = 0;

    sort(c + 1, c + n + 1); // 将数轴上所有点排序

    LL res = 0;
    for (int i = 1; i <= n; i++) res += abs(c[i] - c[(n + 1) / 2]); //距离和

    printf("%lld\n", res);

    return 0;
}
