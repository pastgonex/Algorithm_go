#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int cnt_odd = 0, cnt_even = 0, last_even, last_odd;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x & 1) {
            cnt_odd++;
            last_odd = i;
        }
        else {
            cnt_even++;
            last_even = i;
        }
    }
    if (cnt_odd > 1) {
        cout << last_even << endl;
    }
    else {
        cout << last_odd << endl;
    }
    return 0;
}