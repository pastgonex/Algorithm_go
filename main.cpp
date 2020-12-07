#include<iostream>

using namespace std;

typedef long long ll;

int a, b, q;

int main() {
    cin >> a >> b >> q;  // a^b % q
    int res = 1 % q;//¿¼ÂÇ q=1µÄÇé¿ö
    while (b) {
        if (b & 1) {
            res = res * 1ll * a % q;
        }
        a = (ll) a * a;
        b >>= 1;
    }
    cout << res << endl;
    return 0;
}