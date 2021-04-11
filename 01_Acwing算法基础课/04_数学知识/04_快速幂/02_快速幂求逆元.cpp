#include <iostream>

using namespace std;

typedef long long ll;

int n;

int quick_pow(int a, int k, int p)
{
    ll res = 1 % p;
    while (k) {
        if (k & 1) {
            res = res * a % p;
        }
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

int main()
{
    cin >> n;
    while (n--) {
        int a, p;
        cin >> a >> p;
        if (a % p) {
            cout << quick_pow(a, p - 2, p) << endl;
        }
        else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}