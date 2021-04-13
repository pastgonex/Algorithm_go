// 预处理出阶乘和阶乘的逆元
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10, mod = 1e9 + 7;

int fact[N], infact[N];

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

    // 0的阶乘为1
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * quick_power(i, mod - 2, mod) % mod;
    }

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << (ll)fact[a] * infact[b] % mod * infact[a - b] % mod << endl;
    }

    return 0;
}