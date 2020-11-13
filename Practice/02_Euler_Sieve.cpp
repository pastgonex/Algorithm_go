//
// Created by Genes on 2020/11/12.
//
// 欧拉筛法(线性筛法)

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int v[N], prime[N];
bool st[N];
int cnt;

int primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            v[i] = i;
            prime[++cnt] = i;
        }
        for (int j = 1; prime[j] * i <= n; j++) {
            st[prime[j] * i] = true; //标记合数
            v[prime[j] * i] = prime[j];
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return v[n];
}

int main() {
    int n;
    cin >> n;
    cout << primes(n) << endl;//n的最小质因子
    for (int i = 1; i <= cnt; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << prime[i];
    }
    return 0;
}
