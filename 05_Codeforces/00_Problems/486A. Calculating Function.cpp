#include <iostream>

using namespace std;

typedef long long ll;

ll n;

int main()
{
    cin >> n;
    if (n & 1) {
        cout << -(n / 2 + 1) << endl;
    }
    else {
        cout << n / 2 << endl;
    }
    return 0;
}