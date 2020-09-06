#include<iostream>

using namespace std;

const int N = 1e3 + 10;

int n;
int f[N], w[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (w[i] > w[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}