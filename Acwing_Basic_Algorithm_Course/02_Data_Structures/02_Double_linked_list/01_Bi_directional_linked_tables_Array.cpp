//
// Created by Genes on 2020/12/12.
//
#include<iostream>

#define SIZE 1000010

using namespace std;

struct Node {
    int value;
    int prev, next;
} node[SIZE];

int head, tail, tot;

void initialize() {
    tot = 2;
    head = 1, tail = 2;
    node[head].next = tail;
    node[tail].prev = head;
}

void insert(int p, int val) {
    int q = ++tot;
    node[q].value = val;
    node[node[p].next].prev = q;
    node[q].next = node[p].next;
    node[p].next = q;
    node[q].prev = p;
}

void remove(int p) {
    node[node[p].prev].next = node[p].next;
    node[node[p].next].prev = node[p].prev;
}

void clear() { //数组模拟链表清空
    memset(node, 0, sizeof node);
    head = tail = tot = 0;
}