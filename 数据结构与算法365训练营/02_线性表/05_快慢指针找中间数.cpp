#include <iostream>

using namespace std;

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linklist;

void CreateList_T(Linklist &L)
{
    int n;
    Linklist s, tail;
    L->next = NULL;
    tail = L;
    puts("请输入元素个数n: ");
    scanf("%d", &n);
    puts("尾插法(正序)创建单链表...");
    while (n--)
    {
        s = new Lnode;
        scanf("%d", &s->data);
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
}

Linklist findMiddle(Linklist L)
{
    Linklist p, q;
    // p为快, q为慢, p比 q每次多走一步
    p = L;
    q = L;
    while (p && p->next)
    {
        p = p->next->next;
        q = q->next;
    }
    return q;
}

void ListPrint_L(Linklist L)
{
    Linklist p;
    p = L->next;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    puts("");
}

int main(void)
{
    Linklist L, mid;
    puts("创建单链表L: ");
    CreateList_T(L);
    puts("单链表的数据为: ");
    ListPrint_L(L);
    mid = findMiddle(L);
    printf("单链表的中间节点数据为: %d\n",mid->data);
    return 0;
}
