//
// Created by Genes on 2020/12/13.
//
// 双向链表, 数组模拟

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int e[N], l[N], r[N], idx;

void initialize() {
    r[1] = 2;
    l[2] = 1;
    idx = 3;
}

void add(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[r[k]] = idx;
    l[idx] = k;
    r[k] = idx++;
}

void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int m;

int main() {
    cin >> m;
    initialize();
    string op;
    int k, x;
    while (m--) {
        cin >> op;
        if (op == "L") {
            cin >> x;
            add(1, x);
        } else if (op == "R") {
            cin >> x;
            add(l[2], x);
        } else if (op == "D") {
            cin >> k;
            remove(k + 2); //idx从3开始, 因此第一个插入的数应该是3=1+2 --> k+2
        } else if (op == "IL") {
            cin >> k >> x;
            add(l[k + 2], x);
        } else {
            cin >> k >> x;
            add(k + 2, x);
        }
    }
    for (int i = r[1]; i != 2; i = r[i]) {
        cout << e[i] << " ";
    }
    return 0;
}
