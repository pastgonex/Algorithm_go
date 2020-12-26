//
// Created by Genes on 12/23/2020.
//
// 模拟队列
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int q[N];
int hh, tt;

int main() {
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            q[tt++] = x;
        } else if (op == "pop") {
            if (hh != tt) {
                hh++;
            }
        } else if (op == "empty") {
            if (hh == tt) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << q[hh] << endl;
        }
    }
    return 0;
}