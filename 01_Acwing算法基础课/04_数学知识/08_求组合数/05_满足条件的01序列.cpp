#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10, mod = 1e9 + 7;

// 因为我们%的数是质数， 因此可以通过费马小定理来求逆元
int quick_power(int a, int k, int p)
{
    int res = 1 % p;
    while (k) {
        if (k & 1) {
            res = (ll)res * a % p;
        }
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    int a = n * 2, b = n;
    int res = 1;
    for (int i = a; i > a - b; i--) {
        res = (ll)res * i % mod;
    }

    for (int i = 1; i <= b; i++) {
        res = (ll)res * quick_power(i, mod - 2, mod) % mod;
    }

    res = (ll)res * quick_power(n + 1, mod - 2, mod) % mod;

    cout << res << endl;

    return 0;
}