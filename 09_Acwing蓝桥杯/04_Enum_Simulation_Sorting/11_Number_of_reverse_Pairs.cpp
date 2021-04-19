//
// Created by Genes on 2020/9/13.
//
// 逆序对的数量

#include<iostream>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n;
int q[N], tmp[N];

ll merge_select(int q[], int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    ll res = merge_select(q, l, mid) + merge_select(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else {
            tmp[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++) {
        q[i] = tmp[j];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    cout << merge_select(q, 0, n - 1) << endl;
    return 0;

}
