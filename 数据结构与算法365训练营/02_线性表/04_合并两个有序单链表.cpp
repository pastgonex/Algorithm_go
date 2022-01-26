#include <iostream>
#include <string>

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
    L = new Lnode;
    L->next = NULL;
    tail = L;
    puts("请输入元素个数n: ");
    scanf("%d", &n);
    puts("请依次输入n个整型数(非递减)");
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

void mergeLinklist(Linklist La, Linklist Lb, Linklist &Lc)
{
    Linklist p, q, tail;
    p = La->next;
    q = Lb->next;
    Lc = La;
    tail = Lc; //tail永远指向 Lc的尾部
    while (p && q)
    {
        if (p->data <= q->data)
        {
            tail->next = p;
            tail = p;
            p = p->next;
        }
        else
        {
            tail->next = q;
            tail = q;
            q = q->next;
        }
    }
    tail->next = p ? p : q;
    delete Lb;
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
    Linklist La, Lb, Lc;
    puts("创建有序(非递减)单链表 La");
    CreateList_T(La);
    puts("创建有序(非递减)单链表 Lb");
    CreateList_T(Lb);
    puts("将两个有序(非递减)单链表La和Lb和并为Lc: ");
    mergeLinklist(La, Lb, Lc);
    puts("合并后的记过Lc: ");
    ListPrint_L(Lc);
    return 0;
}
