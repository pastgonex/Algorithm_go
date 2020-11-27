//
// Created by Genes on 2020/11/19.
//
// 数的三次方根

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

double n, m;
int a[N];

// 把n本书分成m组, 每组厚度之和<=size, 是否可行
bool valid(int size) {
    int group = 1, rest = size;
    for (int i = 1; i <= n; i++) {
        if (rest >= a[i]) {
            rest -= a[i];
        } else {
            group++, rest = size - a[i];
        }
    }
    return group <= m;
}

int main() {
    cin >> n >> m;
    int sum_of_ai = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum_of_ai += a[i];
    }
    // 二分答案, 判定"每组厚度之和不超过二分的值"时
    // 能否在m组内把书分完
    int l = 0, r = sum_of_ai;
    while (l < r) {
        int mid = (l + r) / 2;
        if (valid(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}