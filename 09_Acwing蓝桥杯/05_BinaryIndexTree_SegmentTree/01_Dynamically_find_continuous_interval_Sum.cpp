//
// Created by Genes on 2020/9/30.
//
// 动态求连续区间和
// 暴力做法
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int num[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    while (m--) {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0) {
            int sum = 0;
            for (int i = a; i <= b; i++) {
                sum += num[i];
            }
            cout << sum << endl;
        } else if (k == 1) {
            num[a] += b;
        }
    }
    return 0;
}