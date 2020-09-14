//
// Created by Genes on 2020/9/11.
//
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e3 + 10;

int n;
int dp[N], w[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    int res = -1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (w[i] > w[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}

