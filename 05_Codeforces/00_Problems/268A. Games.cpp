#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n, a[N], b[N];
int cnt;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}