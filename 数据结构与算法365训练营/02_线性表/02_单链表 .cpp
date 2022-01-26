#include <iostream>

using namespace std;

#define ElemType int

typedef struct Lnode
{
    ElemType data;      //节点的数据域
    struct Lnode *next; //节点的指针域
} Lnode, *Linklist;     // Linklist 为指向结构体 Lnode的指针类型

bool InitList_L(Linklist &L) // 构造一个空的单链表 L
{
    L = new Lnode; //生成新节点作为头节点, 用头指针 L 指向头节点
    if (!L)
        return false; //生成节点失败
    L->next = NULL;   // 头节点的指针域置空
    return true;      //证明初始化成功
}

void CreateList_H(Linklist &L) //头插法创建单链表
{
    //输入n个元素的值, 建立到头节点的单链表 L
    int n;
    Linklist s; //定义一个指针变量
    L = new Lnode;
    L->next = NULL; //先建立一个带头节点的空链表
    puts("请输入元素个数n:");
    scanf("%d", &n);
    puts("请依次输入n个元素: ");
    puts("头插法创建单链表...");
    while (n--)
    {
        s = new Lnode;         //生成新节点 s
        scanf("%d", &s->data); // 输入元素值赋给新节点的数据域
        s->next = L->next;
        L->next = s; //讲新节点 s 插入到头节点之后
    }
}

void CreateList_T(Linklist &L) //尾插法创建单链表
{
    int n;
    Linklist s, tail; //定义一个指针变量
    L = new Lnode;
    L->next = NULL; //先建立一个带头节点的空链表
    tail = L;       // 让 尾指针指向头节点
    puts("请输入元素个数n:");
    scanf("%d", &n);
    puts("请依次输入n个元素: ");
    puts("尾插法创建单链表...");
    while (n--)
    {
        s = new Lnode;         //生成新节点 s
        scanf("%d", &s->data); // 输入元素值赋给新节点的数据域
        s->next = NULL;
        tail->next = s; // 将新节点s插入尾节点 *tail 之后
        tail = s;       // tail 重新指向新的尾节点 s
    }
}

bool GetElem_L(Linklist L, int i, int &e)
{
    //在带头节点的单链表L中查找第 i 个元素
    //用 e 记录 L 中第 i 个数据元素的值
    int cnt;
    Linklist p;
    p = L->next; //p 指向第一个节点
    cnt = 1;
    while (cnt < i && p)
    {
        p = p->next;
        cnt++;
    }
    if (!p || cnt > i)
        return false; // 没有找到
    e = p->data;      //把数据传递出来
    return true;
}

bool LocateElem_L(Linklist L, int e)
{
    Linklist p = L->next;
    while (p && p->data != e) //顺序向后扫描
        p = p->next;
    if (!p)
        return false; //查找失败, p为 NULL
    return true;
}

bool ListInsert_L(Linklist &L, int i, int e) //单链表的插入
{
    //带头节点的单链表 L 中第 i 个位置插入值为 e 的新节点
    int count;

    Linklist p, s;
    p = L;
    count = 0;
    while (p && count < i - 1) // 查找 i -1 个节点
    {
        p = p->next;
        count++;
    }
    if (!p || count > i - 1) //i>n+1 或者 i<1
        return false;
    s = new Lnode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete_L(Linklist &L, int i) //单链表的删除
{
    //在带头节点的单链表中, 删除第 i 个位置
    int count = 0;
    Linklist p = L, q;
    while (p->next && (count < i - 1)) //查找第 i-1个节点, p指向该节点
    {
        p = p->next;
        count++;
    }
    while (!(p->next) || (count > i - 1))
        return false;
    q = p->next;
    p->next = q->next;
    delete q; //释放删除的节点的过程
    return true;
}

void ListPrint_L(Linklist L) //单链表的输出
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
    puts("2. 创建单链表 (头插法)");
    puts("3. 创建单链表 (尾插法)");
    puts("4. 取值");
    puts("5. 查找");
    puts("6. 插入");
    puts("7. 删除");
    puts("8. 输出");
    puts("0. 退出");
    op = -1;
    while (op != 0)
    {
        puts("请输入数字选择: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1: //初始化一个空的单链表
            if (InitList_L(L))
                puts("初始化一个空的单链表");
            break;
        case 2: //创建单链表(头插法)
            CreateList_H(L);
            puts("头插法创建单链表输出结果: ");
            ListPrint_L(L);
            break;
        case 3: //创建单链表(尾插法)
            CreateList_T(L);
            puts("尾插法创建单链表输出结果: ");
            ListPrint_L(L);
            break;
        case 4: //单链表的按序号取值
            puts("请输入一个位置i用来取值: ");
            scanf("%d", &i);
            if (GetElem_L(L, i, e))
            {
                puts("查找成功");
                printf("第%d个元素是: \n", e);
            }
            else
                puts("查找失败\n");
            break;
        case 5: //单链表的按值查找
            puts("请输入所要查找的元素x: ");
            scanf("%d", &x);
            if (LocateElem_L(L, x))
                puts("查找成功");
            else
                puts("查找失败");
            break;
        case 6: //单链表的插入
            puts("请输入插入的位置和元素(用空格隔开): ");
            scanf("%d%d", &i, &x);
            if (ListInsert_L(L, i, x))
                puts("插入成功.\n");
            else
                puts("插入失败!n");
            break;
        case 7: //单链表的删除
            puts("请输入所要删除的元素位置i: ");
            scanf("%d", &i);
            if (ListDelete_L(L, i))
                puts("删除成功!");
            else
                puts("删除失败!");
            break;
        case 8: //单链表的输出
            puts("当前单链表的数据元素分别为: ");
            ListPrint_L(L);
            puts("");
            break;
        }
    }
    return 0;
}
