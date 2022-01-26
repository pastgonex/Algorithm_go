#include <iostream>

using namespace std;

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linklist;

void CreateList_L(Linklist &L)
{
    int n;
    Linklist s, tail;
    L->next = NULL;
    tail = L;
    puts("请输入元素个数n: ");
    scanf("%d", &n);
    puts("尾插法创建单链表...");
    while (n--)
    {
        s = new Lnode;
        scanf("%d", &s->data);
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
}

Linklist findEndK(Linklist L, int k)
{
    Linklist p, q;
    p = L;
    q = L;
    while (k--)
        p = p->next;
    while (p)
    {
        p = p->next;
        q = q->next;
    }
    return q;
}

void PrintList_L(Linklist L)
{
    Linklist p = L->next;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    puts("");
}

int main(void)
{
    Linklist L;
    puts("创建单链表");
    CreateList_L(L);
    PrintList_L(L);
    puts("请输入k: ");
    int k;
    scanf("%d", &k);
    Linklist ans = findEndK(L, k);
    printf("%d\n", ans->data);
    return 0;
}
