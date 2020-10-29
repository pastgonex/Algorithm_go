//
// Created by Genes on 2020/10/27.
//
// 付账问题
// n个人吃饭, 总共消费s元
// 第i个人带了a[i]元
// 贪心策略:
//      先排序
// a[i]> avg , b[i] = avg
// a[i]< avg,  b[i] = a[i], 然后往后均摊

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 5e5 + 10;

int a[N];
int n;
double s;

int main() {
    scanf("%d%lf", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    double res = 0, avg = s / n;
    for (int i = 0; i < n; i++) {
        double cur = s / (n - i); //往后均摊的平均值
        if (a[i] < cur) {
            cur = a[i];
        }
        res += (cur - avg) * (cur - avg);
        s -= cur;
    }
    printf("%.4lf\n", sqrt(res / n));
    return 0;
}