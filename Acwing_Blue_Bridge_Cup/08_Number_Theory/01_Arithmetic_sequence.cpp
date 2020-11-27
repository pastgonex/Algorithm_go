//
// Created by Genes on 2020/10/29.
//
// 等差数列
// 数论

#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int prime[N];
int st[N];
int cnt;
int v[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[++cnt] = i;
            min_p[i] = i;
        }
        for (int j = 1; primes[j] * i <= n; j++) {
            int t = primes[j] * i;
            st[t] = true;
            min_p[t] = primes[j];
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int d = 0;
    for (int i = 1; i < n; i++) {
        d = gcd(d, a[i] - a[0]); // 每一项和第一项的差, 最后d是每一项和第一项的差的最大公约数
    }
    if (!d) { //如果公差为0, 也就是每一个数字都相等的时候, 直接输出n就行
        printf("%d\n", n);
    } else {
        printf("%d\n", (a[n - 1] - a[0]) / d + 1); //(末项-首项)/d +1 == 总项数
    }
    return 0;
}