//
// Created by Genes on 2020/12/7.
//
// a^b
// 快速幂
#include <iostream>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int a, b, p;

int quick_pow(int a, int b, int mod) {
    int ans = 1 % p;
    while (b) {
        if (b & 1) {
            ans = ans * (ll) a % p; // ans* a^(2^k)
        }
        a = (ll) a * a % p;  // a^(2^(n+1)) = a^(2^n) * a^(2^n)
        b >>= 1;
    }
    return ans;
}

int main() {
    ios;
    cin >> a >> b >> p;
    cout << quick_pow(a, b, p) << endl;
    return 0;
}