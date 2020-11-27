//
// Created by Genes on 2020/11/16.
//
// 快速排序

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) { // 判边界, 如果区间中只有一个数字,或没有数字, 就直接return
        return;
    }
    int x = q[(l + r) >> 1]; //分界点
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r); //递归处理左右两段
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << q[i];
    }
    cout << endl;
    return 0;
}