//
// Created by Genes on 2020/12/12.
//
// 数组模拟单链表

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

// head表示头节点下标
// e[i] 表示节点i的值是多少
// ne[i] 表示节点i的next指针是多少(节点i的下一个点的下标是什么)
// idx 存储我们当前已经用到了哪个点(0,1,2...)
int head, e[N], ne[N], idx;

// 初始化
void initialize() {
    head = -1;
    idx = 0;
}

// 将x插到头节点
void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

int m;

int main() {
    initialize();
    cin >> m;
    while (m--) {
        char op;
        cin >> op;
        int x, k;
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'I') {
            cin >> k >> x;
            add(k - 1, x); // k-1, 因为0号点是第一个插入的点
        } else {
            cin >> k;
            if (!k) {
                head = ne[head]; // 看了我半天....
            } else remove(k - 1);
        }
    }
    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    return 0;
}