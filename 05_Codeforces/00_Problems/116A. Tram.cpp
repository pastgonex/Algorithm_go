#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int cur = 0, maxn = 0xcfcfcfcf;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cur -= a, cur += b;
        maxn = max(cur, maxn);
    }
    cout << maxn << endl;

    return 0;
}