//
// Created by Genes on 2020/12/6.
//
#include <iostream>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main() {
    ios;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0, j = m - 1; i < n; i++) {
        while (a[i] + b[j] > x && j >= 0) {
            j--;
        }
        if (a[i] + b[j] == x) {
            cout << i << " " << j << endl;
            break;
        }
    }
    return 0;
}