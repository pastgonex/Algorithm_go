#include <iostream>

using namespace std;

#define ElemType int

typedef struct Lnode
{
    struct Lnode *pre;
    ElemType data;
    struct Lnode *next;
} Lnode, *Linklist;

bool InitDoubleLinkList(Linklist &L)
{
    L = new Lnode;
    if (!L)
        return false;
    L->pre = NULL;
    L->next = NULL;
    return true;
}

void CreateList_H(Linklist &L)
{
    int n;
    Linklist s;
    L = new Lnode;
    L->next = NULL;
    L->pre = NULL;
    puts("请输入元素个数n:");
    scanf("%d", &n);
    puts("请依次输入n个元素: ");
    puts("头插法创建双向链表...");
    while (n--)
    {
        s = new Lnode;
        scanf("%d", &s->data);
        s->next = L->next;
        s->pre = L;
        L->next = s;
    }
}

void CreateList_T(Linklist &L)
{
    int n;
    Linklist s, tail;
    L = new Lnode;
    L->next = NULL;
    L->pre = NULL;
    tail = L;
    puts("请输入元素个数n:");
    scanf("%d", &n);
    puts("请依次输入n个元素: ");
    puts("尾插法创建双向链表...");
    while (n--)
    {
        s = new Lnode;
        scanf("%d", &s->data);
        s->next = NULL;
        s->pre = tail;
        tail->next = s;
        tail = s;
    }
}

bool preInsert_L(Linklist &L, int i, int e)
{
    int count;
    Linklist p, s;
    p = L;
    count = 0;
    while (p && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (!p || count > i - 1)
        return false;
    s = new Lnode;
    s->data = e;
    s->pre = p;
    s->next = p->next;
    p->next->pre = s;
    p->next = s;
    return true;
}

bool afterInsert_L(Linklist &L, int i, int e)
{
    int count;
    Linklist p, s;
    p = L;
    count = 0;
    while (p && count < i)
    {
        p = p->next;
        count++;
    }
    if (!p || count > i)
        return false;
    s = new Lnode;
    s->data = e;
    s->pre = p;
    s->next = p->next;
    p->next->pre = s;
    p->next = s;
    return true;
}

bool LocateElem_L(Linklist L, int e)
{
    Linklist p = L->next;
    while (p && p->data != e)
        p = p->next;
    if (!p)
        return false;
    return true;
}

bool GetElem_L(Linklist L, int i, int &e)
{
    int cnt;
    Linklist p;
    p = L->next;
    cnt = 1;
    while (cnt < i && p)
    {
        p = p->next;
        cnt++;
    }
    if (!p || cnt > i)
        return false;
    e = p->data;
    return true;
}

bool ListDelete_L(Linklist &L, int i)
{
    Linklist p;
    p = L;
    int cnt = 0;
    while (p && cnt < i)
    {
        p = p->next;
        cnt++;
    }
    if (!p || cnt > i)
        return false;
    if (!p->next)
    {
        p->pre->next = NULL;
        delete p;
        return true;
    }
    p->pre->next = p->next;
    p->next->pre = p->pre;
    delete p;
    return true;
}

void ListPrint_L(Linklist L)
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
    int i, x, e, op;
    Linklist L;
    puts("1. 初始化");
    puts("2. 创建双向链表 (头插法)");
    puts("3. 创建双向链表 (尾插法)");
    puts("4. 取值");
    puts("5. 查找");
    puts("6. 前插");
    puts("7. 后插");
    puts("8. 删除节点");
    puts("9. 输出");
    puts("0. 退出");
    op = -1;
    while (op != 0)
    {
        puts("请输入数字选择: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1: //初始化一个空的双向链表
            if (InitDoubleLinkList(L))
                puts("初始化一个空的双向链表");
            break;
        case 2: //创建双向链表(头插法)
            CreateList_H(L);
            puts("头插法创建双向链表输出结果: ");
            ListPrint_L(L);
            break;
        case 3: //创建双向链表(尾插法)
            CreateList_T(L);
            puts("尾插法创建双向链表输出结果: ");
            ListPrint_L(L);
            break;
        case 4: //双向链表的按序号取值
            puts("请输入一个位置i用来取值: ");
            scanf("%d", &i);
            if (GetElem_L(L, i, e))
            {
                puts("查找成功");
                printf("第%d个元素是: %d\n", i, e);
            }
            else
                puts("查找失败\n");
            break;
        case 5: //双向链表的按值查找
            puts("请输入所要查找的元素x: ");
            scanf("%d", &x);
            if (LocateElem_L(L, x))
                puts("查找成功");
            break;
        case 6:
            puts("请输入前插的位置和元素(用空格隔开): ");
            scanf("%d%d", &i, &x);
            if (preInsert_L(L, i, x))
                puts("插入成功.\n");
            else
                puts("插入失败!n");
            break;
        case 7: //双向链表的后插
            puts("请输入后插的位置和元素(用空格隔开): ");
            scanf("%d%d", &i, &x);
            if (afterInsert_L(L, i, x))
                puts("插入成功.\n");
            else
                puts("插入失败!n");
            break;
        case 8:
            //双向链表的删除
            puts("请输入所要删除的元素位置i: ");
            scanf("%d", &i);
            if (ListDelete_L(L, i))
                puts("删除成功!");
            else
                puts("删除失败!");
            break;
        case 9:
            //双向链表的输出
            puts("当前双向链表的数据元素分别为: ");
            ListPrint_L(L);
            puts("");
            break;
        }
    }
    return 0;
}
