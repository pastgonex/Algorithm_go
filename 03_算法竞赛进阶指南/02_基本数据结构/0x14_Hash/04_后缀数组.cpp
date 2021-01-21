/*
 * Project: 0x14_Hash
 * File Created:Tuesday, January 19th 2021, 11:06:37 pm
 * Author: Bug-Free
 * Problem:
 */
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 3e5 + 10, P = 131;

int n;
char str[N];
ULL h[N], p[N];
int sa[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int get_max_common_prefix(int a, int b) {
    int l = 0, r = min(n - a + 1, n - b + 1);
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (get(a, a + mid - 1) != get(b, b + mid - 1)) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}

bool cmp(int a, int b) {
    int l = get_max_common_prefix(a, b);  // 获取a和b的最长公共前缀
    int av = a + l > n ? INT_MIN : str[a + l];  //如果是空的就直接赋成最小值即可
    int bv = b + l > n ? INT_MIN : str[b + l];
    return av < bv;  //返回字典序较小的那一个
}

int main() {
    cin >> (str + 1);
    n = strlen(str + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
        sa[i] = i;  //  sa = {1,2, 3, .....n} 表示从 i~n的后缀
    }

    sort(sa + 1, sa + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        cout << sa[i] - 1 << " ";
    }

    puts("");

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << "0 ";
        } else {
            cout << get_max_common_prefix(sa[i - 1], sa[i]) << " ";
        }
    }
    puts("");

    return 0;
}
