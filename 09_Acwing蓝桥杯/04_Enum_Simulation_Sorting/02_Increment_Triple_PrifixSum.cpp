//
// Created by Genes on 2020/9/15.
//
// 递增三元组
// 前缀和做法

#include<iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n;
int cnt_a[N], cnt_c[N];
int s_a[N], s_c[N];
int a[N], b[N], c[N];
ll res;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {// 前缀和从1开始
        cin >> a[i];
        cnt_a[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        cnt_c[c[i]]++;
    }
    s_a[0] = cnt_a[0];
    s_c[0] = cnt_c[0];

    // 处理前缀和
    for (int i = 1; i < N; i++) {
        s_a[i] = s_a[i - 1] + cnt_a[i];
        s_c[i] = s_c[i - 1] + cnt_c[i];
    }

    //遍历b数组
    for (int i = 1; i <= n; i++) {
        int B = b[i];
        res += (ll) s_a[B - 1] * (s_c[N - 1] - s_c[B]);
    }

    cout << res << endl;
    return 0;

}
