// 卢卡斯定理
#include <iostream>

using namespace std;

typedef long long ll;

int quick_power(int a, int k, int p)
{
    int res = 1;
    while (k) {
        if (k & 1) {
            res = (ll)res * a % p;
        }
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

int C(int a, int b, int p)
{
    if (b > a) {
        return 0;
    }
    int res = 1;
    // a!/(b!(a-b)!) = (a-b+1)*...*a / b! 分子有b项
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (ll)res * j % p;
        res = (ll)res * quick_power(i, p - 2, p) % p;
    }
    return res;
}

int lucas(ll a, ll b, int p)
{
    if (a < p && b < p) {
        return C(a, b, p);  //lucas递归终点是C_{a0}^{b0}
    }
    return (ll)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;  //a%p后肯定是<p的,所以可以用C(),但a/p后不一定<p 所以用lucas继续递归
}

int main()
{
    int n;
    cin >> n;

    while (n--) {
        ll a, b;
        int p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }
    return 0;
}