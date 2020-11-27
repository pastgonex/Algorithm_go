//
// Created by Genes on 2020/11/20.
//
// 递归实现排列型枚举

#include<iostream>

using namespace std;

const int N = 1e1 + 5;

int n;
int alls[N];
bool st[N];

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                cout << " ";
            }
            cout << alls[i];
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            alls[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    dfs(1);
    return 0;
}