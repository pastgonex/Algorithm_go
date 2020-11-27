//
// Created by Genes on 2020/11/16.
//
// 归并
// 逆序对的数量

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

int n;
int q[N], tmp[N];
ll ans;

void merge_sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int res = 0;
    int mid = (l + r) >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        } else {
            tmp[k++] = q[j++];
            ans += mid - i + 1;
        }

    }
    while (i <= mid) {
        tmp[k++] = q[i++];
    }
    while (j <= r) {
        tmp[k++] = q[j++];
    }
    for (int i = l, j = 0; i <= r; i++, j++) {
        q[i] = tmp[j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    merge_sort(0, n - 1);
    cout << ans << endl;
    return 0;
}