//
// Created by Genes on 2020/12/17.
//
// 模拟栈
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int m;
int tt = -1;
int stk[N];

void push(int x) {
    stk[++tt] = x;
}

bool is__empty() {
    return tt == -1;
}

int query() {
    return stk[tt];
}

void pop() {
    tt--;
}

int main() {
    cin >> m;
    string op;
    while (m--) {
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        } else if (op == "empty") {
            is__empty() ? (cout << "YES" << endl) : (cout << "NO" << endl);
        } else {
            cout << stk[tt] << endl;
        }
    }
    return 0;
}
