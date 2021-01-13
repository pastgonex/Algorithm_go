/*
 * Project: 0x16_Trie
 * File Created:Friday, January 8th 2021, 5:30:19 am
 * Author: Bug-Free
 * Problem:143. 最大异或对
 */

// brute-force 暴力
// #include <iostream>

// using namespace std;

// const int N = 1e5 + 10;

// int n;
// int a[N];

// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     int res = 0;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             res = max(res, a[i] ^ a[j]);
//         }
//     }
//     cout << res << endl;
//     return 0;
// }

// Trie字典树做法
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 3e6 + 1e5;

int a[N], son[M][2];

int n, idx, res;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int& s = son[p][x >> i & 1];
        if (!s) {
            s = ++idx;
        }
        p = s;
    }
}

int query(int x) {
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--) {
        int s = x >> i & 1;
        if (son[p][!s]) {
            res += 1 << i;
            p = son[p][!s];
        } else {
            p = son[p][s];
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(x);
        res = max(res, query(x));
    }
    cout << res << endl;
    return 0;
}
