#include <iostream>

using namespace std;

int t;

int main()
{
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        a % b ? cout << b - a % b << endl : cout << 0 << endl;
    }
    return 0;
}