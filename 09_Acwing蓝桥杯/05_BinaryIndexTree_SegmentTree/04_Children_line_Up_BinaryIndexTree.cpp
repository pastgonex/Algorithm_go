//
// Created by Genes on 2020/10/8.
//
// 小朋友排队
// 树状数组做法
// 可以通过树状数组来求  比A大的数 | A | 比A小的数

#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

typedef long long ll;

int n;
int c[N], a[N];
int sum[N];  // sum数组存储每个小朋友的不高兴度

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (; x < N; x += lowbit(x)) {
        c[x] += v;
    }
}

int ask(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) {
        ans += c[x];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]++;  //身高是从0开始,所以++ 从1开始
    }
    // 求每个数前面有多少个数比它大
    for (int i = 0; i < n; i++) {
        sum[i] = ask(N - 1) - ask(a[i]);
        add(a[i], 1);
    }

    //清空树状数组
    memset(c, 0, sizeof c);

    //找出比这个数小的数有多少个
    //注意这里必须倒着更新，否则无法算出高的层的数值
    for (int i = n - 1; i >= 0; i--) {
        sum[i] += ask(a[i] - 1);
        add(a[i], 1);
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        //等差数列求和 不高兴度的总和为从1+2+..+sum[i]
        res += (ll)sum[i] * (sum[i] + 1) / 2;
    }

    cout << res << endl;
    return 0;
}
