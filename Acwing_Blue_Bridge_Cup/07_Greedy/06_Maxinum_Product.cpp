//
// Created by Genes on 2020/10/27.
//
// 乘积最大
// 贪心

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 9;

typedef long long LL;

int n, k;
int a[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    int res = 1;
    int l = 0, r = n - 1;
    int sign = 1; // 正
    if (k & 1) { //将奇数情况转换为偶数情况
        res = a[r--]; //先取最大值
        k--; //变成偶数的情况了
        if (res < 0) {
            sign = -1;
        }
    }
    while (k) {
        LL x = (LL) a[l] * a[l + 1], y = (LL) a[r - 1] * a[r];
        if (x * sign > y * sign) {
            //sign是-1, 返回的是x,y中较小的,  sign是1, 返回x,y中较大的
            res = x % mod * res % mod;
            l += 2;
        } else {
            res = y % mod * res % mod;
            r -= 2;
        }
        k -= 2;
    }
    printf("%d\n", res);
    return 0;
}