//
// Created by Genes on 2020/11/13.
//
// 鸣人的影分身  dfs

#include<iostream>

using namespace std;

int m, n;
int res;

// 把 m 分成 n 个数的和
void dfs(int t, int start, int state) { // t剩余的能量, start下一个分身的值, state已经完成的分身
    if (state == n && t == 0) {
        res++;
        return;
    }
    if (state >= n) {
        return;
    }
    for (int i = start; i <= t; i++) {
        dfs(t - i, i, state + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        res = 0;
        cin >> m >> n;
        dfs(m, 0, 0);
        cout << res << endl;
    }
    return 0;
}