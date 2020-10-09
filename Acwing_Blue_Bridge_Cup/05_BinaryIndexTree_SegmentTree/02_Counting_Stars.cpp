//
// Created by Genes on 2020/10/4.
//
// 数星星
// 树状数组
// 需要注意的是, 树状数组的下标必须是从1开始的, 所以我们把所有的x往右边平移一个单位就好 x++

#include<iostream>

using namespace std;

const int N = 3.2e4 + 5;

int n;
int c[N], level[N];

int lowbit(int x) {
    return x & -x;
}

int ask(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) {
        ans += c[x];
    }
    return ans;
}

void add(int x) {
    for (; x < N; x += lowbit(x)) {
        c[x]++; //后面的都加一个星星
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x++;
        level[ask(x)]++;
        add(x);
    }
    for (int i = 0; i < n; i++) {
        cout << level[i] << endl;
    }
    return 0;
}