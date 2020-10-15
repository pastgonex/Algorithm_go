//
// Created by Genes on 2020/10/14.
//
// 完全二叉树的权值
// 双指针
// 每一段的长度是 i+2^(d-1), 并且j不能越界
// 具有n个结点的完全二叉树的深度 log2k +1
#include<iostream>
#include<climits>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

int n;
int a[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll maxN = INT_MIN;
    int depth = 1;
    for (int d = 1, i = 1; i <= n; d++, i *= 2) {
        ll sum = 0;
        for (int j = i; j < i + (1 << (d - 1)) && j <= n; j++) {
            sum += a[j];
        }
        if (maxN < sum) {
            depth = d;
            maxN = sum;
        }
    }
    cout << depth << endl;
    return 0;
}
