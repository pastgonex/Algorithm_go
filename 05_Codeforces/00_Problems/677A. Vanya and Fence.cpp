#include <iostream>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;

    int res = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x <= k) {
            res += 1;
        }
        else {
            res += 2;
        }
    }
    cout << res << endl;
    return 0;
}