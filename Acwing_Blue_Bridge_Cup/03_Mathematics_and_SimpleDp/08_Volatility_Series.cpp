//
// Created by Genes on 2020/9/12.
//
// 波动数列

/*
1.这个数列中的后一项总是比前一项增加a或者减少b

2.则s=x+d1 + x+d1+d2 + x+d1+d2+d3 +... x+d1+d2+...dn-1;
s=n*x + n-1*d1 + n-2*d2 + ... 1*dn-1;

(s-(n-1*d1 + x-2*d2 + n-3*d3 +... 1*dn-1))/n == x;

3.由于数列为整数，则(s-(n-1*d1 + x-2*d2 + n-3*d3 +... 1*dn-1)) 是n的倍数

4.则i-1个数之和的情况下，c为前项之和，第i项为i*a
i-1,c+(i*a) = j(mod n)
c=j-(a*i)(mod n)
则有f(i-1,j-(a*i)(mod n)
1.状态表示：f[i][j]表示要选i个a或者-b且余数为j的所有集合的数量。
2.状态计算：第i个可以选a或者-b。
*/


#include<iostream>

using namespace std;

const int N = 1e3 + 10, MOD = 1e8 + 7;

int dp[N][N];

int get_mod(int a, int b) { // 求a除以b的正余数
    return (a % b + b) % b;
}

int n, s, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s >> a >> b;
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = (dp[i - 1][get_mod(j - a * (n - i), n)] + dp[i - 1][get_mod(j + b * (n - i), n)]) % MOD;
        }
    }
    cout << dp[n - 1][get_mod(s, n)] << endl;
    return 0;
}