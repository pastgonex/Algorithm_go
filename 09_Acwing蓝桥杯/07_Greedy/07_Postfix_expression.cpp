//
// Created by Genes on 2020/10/28.
//
// 后缀表达式
// 贪心
/*
    M=0, 直接算所有的和
    M>0, 取一个最小值和一个最大值, 减去最小值, 加上最大值, 对于中间所有数, 如果是正数, 就给他一个正号, 如果是负数, 则给他一个负号(负负得正)
 */
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 2e5 + 10;

typedef long long LL;

int a[N];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int k = n + m + 1;
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }
    LL res = 0;
    if (!m) {
        for (int i = 0; i < k; i++) {
            res += a[i];
        }
    } else {
        sort(a, a + k);
        res = a[k - 1] - a[0];
        for (int i = 1; i < k - 1; i++) {
            res += abs(a[i]);
        }
    }
    printf("%lld\n", res);
    return 0;
}