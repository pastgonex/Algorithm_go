//
// Created by Genes on 2020/10/11.
//
// 复数的四则运算

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

//小数1位
int judge(double x) {
    return fabs(x) < 0.05 ? 0 : 1;
}

void solve(double e, double f) {
    if (judge(e) == 0 && judge(f) == 0) {
        printf("0.0\n");
    } else if (judge(e) == 0) {
        printf("%.1fi\n", f);
    } else if (judge(f) == 0) {
        printf("%.1f\n", e);
    } else {
        printf("%.1f%c%.1fi\n", e, f < 0 ? '-' : '+', fabs(f));
    }
}

int main() {
    double a, b, c, d, e, f;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    printf("(%.1f%c%.1fi) + (%.1f%c%.1fi) = ", a, b < 0 ? '-' : '+', fabs(b), c, d < 0 ? '-' : '+', fabs(d));
    e = a + c;
    f = b + d;
    solve(e, f);
    printf("(%.1f%c%.1fi) - (%.1f%c%.1fi) = ", a, b < 0 ? '-' : '+', fabs(b), c, d < 0 ? '-' : '+', fabs(d));
    e = a - c;
    f = b - d;
    solve(e, f);
    printf("(%.1f%c%.1fi) * (%.1f%c%.1fi) = ", a, b < 0 ? '-' : '+', fabs(b), c, d < 0 ? '-' : '+', fabs(d));
    e = a * c - b * d;
    f = a * d + b * c;
    solve(e, f);
    printf("(%.1f%c%.1fi) / (%.1f%c%.1fi) = ", a, b < 0 ? '-' : '+', fabs(b), c, d < 0 ? '-' : '+', fabs(d));
    e = (a * c + b * d) / (c * c + d * d);
    f = (b * c - a * d) / (c * c + d * d);
    solve(e, f);
    return 0;
}
