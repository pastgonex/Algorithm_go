//
// Created by Genes on 2020/12/11.
//
// 电影

#include<iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N], c[N];//存原坐标
int arr[N * 3];//存离散化之后的坐标
int num[N * 3];
int sum[N * 3];
int n, m;
int cnt, mm;

// 离散化
void discrete() {
    sort(arr + 1, arr + cnt + 1);
    for (int i = 1; i <= n; i++) { //去重
        if (i == 1 || a[i] != a[i - 1]) {
            num[++mm] = arr[i];
        }
    }
}

int find(int x) {
    int l = 1, r = cnt;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (arr[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        arr[++cnt] = a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        arr[++cnt] = b[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        arr[++cnt] = c[i];
    }

    discrete(); //离散化

    for (int i = 1; i <= n; i++) {
        int id = find(a[i]);
        ++sum[id];
    }

    int bmax = -1, cmax = -1, ans = 0;
    for (int i = 1; i <= m; i++) {
        int x = find(b[i]);
        int y = find(c[i]);
        if (sum[x] > bmax) { //优先考虑让高兴的人最多
            bmax = sum[x], cmax = sum[y];
            ans = i;
        } else {
            if (sum[x] == bmax && sum[y] > cmax) {
                bmax = sum[x], cmax = sum[y];
                ans = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}