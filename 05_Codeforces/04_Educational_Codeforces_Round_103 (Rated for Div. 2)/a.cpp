#include <iostream>

using namespace std;

int n, k;
int t;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        while (k < n) {
            k *= 2;
        }
        int temp = k % n;
        if (k == 0) {
            cout << k / n << endl;
        }
        else {
            cout << k / n + 1 << endl;
        }
    }
    return 0;
}