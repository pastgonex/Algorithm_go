//
// Created by Genes on 2020/12/8.
//
// 64位整数乘法

#include <iostream>

using namespace std;

typedef long long ll;

ll a, b, q;

ll slow_mul(ll a, ll b, ll mod) {
    ll ans = 0;
    while (b) {
        if (b & 1) {
            ans = (ans + a) % mod;
        }
        a = a * 2 % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    cin >> a >> b >> q;
    cout << slow_mul(a, b, q) << endl;  //龟速乘
    return 0;
}
