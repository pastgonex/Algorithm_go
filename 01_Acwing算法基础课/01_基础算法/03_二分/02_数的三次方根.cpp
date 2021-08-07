//
// Created by Genes on 2020/11/19.
//
// 数的三次方根

#include <iostream>

using namespace std;

double n;

int main()
{
    scanf("%lf", &n);
    double l = -1e4, r = 1e4;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    printf("%lf\n", r);
    return 0;
}