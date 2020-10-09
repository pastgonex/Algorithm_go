//
// Created by Genes on 2020/10/8.
//
// 小朋友排队
// 归并排序

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

int n;

struct {
    int h; //身高
    int idx;//上一次位置
    ll m; //移动长度
} q[N], tmp[N];

void merge_sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    int k = l, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i].h <= q[j].h) {
            tmp[k++] = q[i++];
        } else {
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = q[i++];
    }
    while (j <= r) {
        tmp[k++] = q[j++];
    }
    //更新上一位置 idx
    //将本次移动长度累加到总长度
    for (i = l; i < k; i++) {
        q[i] = {tmp[i].h, i, tmp[i].m + abs(tmp[i].idx - i)};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q[i].h;
        q[i].idx = i;
    }
    merge_sort(1, n);
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (q[i].m + 1) * q[i].m / 2;
    }
    cout << cnt << endl;
    return 0;
}
