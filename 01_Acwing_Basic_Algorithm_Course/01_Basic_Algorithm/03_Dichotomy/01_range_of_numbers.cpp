//
// Created by Genes on 2020/11/18.
//
// 数的范围

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, q;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int k;
        cin >> k;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (a[l] != k) {
            cout << "-1 -1" << endl;
        } else {
            cout << l << " ";
            // 此时的=k区间的左端点, 更新一下r的值
            r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (a[mid] <= k) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            cout << l << endl;
        }
    }
    return 0;
}

