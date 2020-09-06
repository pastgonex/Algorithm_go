//
// Created by Genes on 2020/9/6.
//
#include<iostream>
#include<cstring>

using namespace std;

const int N = 5e1 + 5;

int dp[N];

int f(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    } else {
        dp[n] = f(n - 1) + f(n - 2);
        return dp[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    dp[1] = 1;
    f(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << dp[i];
    }
    return 0;
}