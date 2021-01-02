//
// Created by Genes on 2020/12/2.
//
//增减序列 IncDec Sequence
#include <iostream>
#include<algorithm>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

int n;
ll a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    ios;
    cin >> n;
    ll p = 0, q = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    b[1] = a[1];
    b[2] -= a[1];
    for (int i = 2; i <= n; i++) { // b2~bn
        insert(i, i, a[i]);// 可以直接构造, c=a[i]-a[i-1]
        if (b[i] > 0) {
            p += b[i];
        } else {
            q -= b[i];
        }
    }
    cout << max(p, q) << endl << abs(p - q) + 1 << endl;
    return 0;
}