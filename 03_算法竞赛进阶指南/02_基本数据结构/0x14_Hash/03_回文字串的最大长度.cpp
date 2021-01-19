/*
 * Project: 0x14_Hash
 * File Created:Monday, January 19th 2021, 10:01:14 am
 * Author: Bug-Free
 * Problem:AcWing 139. 回文子串的最大长度
 */
#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 2e6 + 10, P = 131;

ULL h1[N], h2[N], p[N];

char str[N];

ULL get(ULL h[], int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int T = 1;
    while (cin >> (str + 1), strcmp(str + 1, "END")) {
        int n = strlen(str + 1);
        for (int i = n * 2; i; i -= 2) {
            str[i] = str[i / 2];
            str[i - 1] = 'a' + 26;
        }

        n *= 2;

        p[0] = 1;
        for (int i = 1, j = n; i <= n; i++, j--) {
            h1[i] = h1[i - 1] * P + str[i];
            h2[i] = h2[i - 1] * P + str[j];
            p[i] = p[i - 1] * P;
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            int l = 0, r = min(i - 1, n - i);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (get(h1, i - mid, i - 1) !=
                    get(h2, n - (i + mid) + 1, n - (i + 1) + 1)) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            if (str[i - l] <= 'z') {
                res = max(res, l + 1);
            } else {
                res = max(res, l);
            }
        }
        cout << "Case " << T++ << ": " << res << endl;
    }
    return 0;
}
