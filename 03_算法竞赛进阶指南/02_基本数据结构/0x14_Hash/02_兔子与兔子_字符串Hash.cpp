/*
 * Project: 0x14_Hash
 * File Created:Monday, January 18th 2021, 2:44:28 pm
 * Author: Bug-Free
 * Problem:AcWing 138. 兔子与兔子
 */
#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 3, P = 1e5 + 3;

int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> (str + 1) >> m;

    n = strlen(str);

    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i - 1];
        p[i] = p[i - 1] * P;
    }

    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
