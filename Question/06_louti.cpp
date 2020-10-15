//
// Created by Genes on 2020/10/11.
//
//爬楼梯

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long f(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    vector<long long> dp;
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(4);
    for (int i = 3; i <= n; i++) {
        dp.push_back((dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000007);
    }
    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    long long z = f(n);

    cout << z << endl;

    return 0;
}