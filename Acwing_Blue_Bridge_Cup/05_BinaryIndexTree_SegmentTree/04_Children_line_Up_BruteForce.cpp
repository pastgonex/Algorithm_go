//
// Created by Genes on 2020/10/8.
//
// 小朋友排队
// 求出 a[i]的逆序对
// 暴力做法 ,直接两重循环或者 使用 归并排序

#include<iostream>

using namespace std;

const int N = 1e6 + 10;

typedef long long ll;

int n;
int a[N];
ll sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                res++;
            }
        }
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                res++;
            }
        }
        sum[i] = res;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x = sum[i];
        ans += (x + 1) * x / 2;
    }
    cout << ans << endl;
    return 0;
}