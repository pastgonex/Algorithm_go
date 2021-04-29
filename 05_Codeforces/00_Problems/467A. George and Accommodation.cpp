#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;

    int res = 0;
    while (n--) {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}