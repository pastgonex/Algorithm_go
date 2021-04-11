#include <iostream>

using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main()
{
    int n;
    cin >> n;

    bool flag = false;
    ll a1, m1, a2, m2;
    cin >> a1 >> m1;

    for (int i = 0; i < n - 1; i++) {
        cin >> a2 >> m2;
        ll k1, k2;
        ll d = exgcd(a1, -a2, k1, k2);

        if ((m2 - m1) % d) {
            flag = true;
            break;
        }

        k1 = k1 * (m2 - m1) / d;
        ll t = a2 / d;
        k1 = (k1 % t + t) % t;
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }
    if (!flag) {
        cout << (m1 % a1 + a1) % a1 << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}