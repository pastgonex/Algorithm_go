//
// Created by Genes on 2020/12/17.
//
// Editor 编辑器

#include<iostream>

#define INF 0x3f3f3f3f

using namespace std;

const int N = 1e6 + 10;

int stk_left[N], stk_right[N];
int t1,t2;

int q;
string op;
int f[N], sum[N];

int main() {
    f[0] = -INF;
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == "I") {
            int x;
            cin >> x;
            stk_left[++t1] = x;
            sum[t1] = sum[t1 - 1] + stk_left[t1];
            f[t1] = max(f[t1 - 1], sum[t1]);
        } else if (op == "D") {
            if (t1) {
                t1--;
            }
        } else if (op == "L") {
            if (t1) {
                stk_right[++t2] = stk_left[t1--];
            }
        } else if (op == "R") {
            if (t2) {
                stk_left[++t1] = stk_right[t2--];
                sum[t1] = sum[t1 - 1] + stk_left[t1];
                f[t1] = max(f[t1 - 1], sum[t1]);
            }
        } else {
            int k;
            cin >> k;
            cout << f[k] << endl;
        }
    }
    return 0;
}
