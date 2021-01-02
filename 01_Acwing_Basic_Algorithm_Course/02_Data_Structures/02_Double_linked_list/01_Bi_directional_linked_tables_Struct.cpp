//
// Created by Genes on 2020/12/12.
//
// 双向链表结构体实现

#include<iostream>

using namespace std;

struct Node {
    int value;// 数据
    Node *prev, *next;//指针
};

Node *head, *tail;

void initialize() {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
}

// 在p后插入包含数据val的新节点
void insert(Node *p, int val) {
    Node *q = new Node();
    q->value = val;
    q->next = p->next;
    p->next->prev = q;
    p->next = q;
    q->prev = p;
}

// 删除p
void remove(Node *p) {
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}

void recycle() {//链表内存回收
    while (head != tail) {
        head = head->next;
        delete head->prev;
    }
    delete tail;
}