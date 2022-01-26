/*
 * Project: 11_哈希表
 * File Created:Sunday, January 17th 2021, 6:15:10 pm
 * Author: Bug-Free
 * Problem:AcWing 841. 字符串哈希
 */
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m;
    cin >> (str + 1);
    p[0] = 1;  // p^0 =1;

    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i];
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
