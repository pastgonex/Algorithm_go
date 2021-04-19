//
// Created by Genes on 2020/8/30.
//
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

int main() {
    int n, k;
    ll ans=0;
    ll s[N] = {0}, cnt[N] = {0};

    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    cnt[0] = 1; //// 我们默认第一个位置(s[0]) 有数(0%k==0), 所以初始化cnt[0]=1;
    for (int r = 1; r <= n; r++) {
        ans += cnt[s[r] % k];
        cnt[s[r] % k]++; // cnt[i] 表示余数是i的数有多少个
        //余数是s[R]%k的数多了一个, 因此让cnt[R%k]++
    }
    cout << ans << endl;
    return 0;
};

