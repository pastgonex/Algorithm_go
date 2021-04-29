// 2*k-1,    2*(k-mid);
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll n, k;

int main()
{
    cin >> n >> k;
    ll mid;
    if (n & 1) {
        mid = n / 2 + 1;
    }
    else {
        mid = n / 2;
    }
    if (k <= mid) {
        cout << k * 2 - 1 << endl;
    }
    else {
        cout << 2 * (k - mid) << endl;
    }
    return 0;
}