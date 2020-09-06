// 有单调性一定可以二分

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

double x;

int main() {
    scanf("%lf", &x);
    double l = -1e4, r = -l;
    while (r - l > 1e-8) // r 和 l的差距>1e-8 就继续
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    printf("%lf", l); //在精度范围内, 输出l或者r 都可以
    return 0;
}
