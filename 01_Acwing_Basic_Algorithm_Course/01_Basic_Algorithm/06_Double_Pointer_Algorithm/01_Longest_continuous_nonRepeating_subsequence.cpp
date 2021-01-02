//
// Created by Genes on 2020/12/4.
//
// 最长连续不重复子序列
// 双指针

#include <algorithm>
#include <iostream>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], cnt[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = i; j < n; j++) {
//            if (check(i, j)) {
//                res = max(res, j - i + 1);
//            }
//        }
//    }
    for (int i = 0, j = 0; i < n; i++) {
        cnt[a[i]]++;
        while (cnt[a[i]] > 1) {
            cnt[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}