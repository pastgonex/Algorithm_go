#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_n = 0, min_n = 0;
    for (int i = 0; i < n; i++) {
        if (a[min_n] >= a[i]) {
            min_n = i;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[max_n] <= a[i]) {
            max_n = i;
        }
    }
    int t = max_n + n - 1 - min_n;
    max_n < min_n ? cout << t << endl : cout << t - 1 << endl;
    return 0;
}