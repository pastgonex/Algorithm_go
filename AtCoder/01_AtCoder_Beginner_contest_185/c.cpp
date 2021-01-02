#include <iostream>

using namespace std;

int l;

typedef long long ll;

int main() {
    cin >> l;
    ll res = 1;
    l--;
    for (int i = 1; i <= 11; i++) {
        res *= l;
        l--;
        res /= i;
    }
    cout << res << endl;
    return 0;
}
