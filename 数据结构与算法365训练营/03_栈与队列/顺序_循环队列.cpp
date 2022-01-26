#include <iostream>

using namespace std;

const int Max_Size = 100;

#define DataType int

typedef struct SqQueue
{
    DataType *base;  //基地址
    int front, tail; //头和尾的位置
} SqQueue;

//循环队列的初始化
bool InitQueue(SqQueue &Q)
{
    Q.base = new int[Max_Size]; //分配空间
    if (!Q.base)
        return false;
    Q.front = Q.tail = 0; //初识位置是 0
    return true;
}

//循环队列的入队
bool EnQueue(SqQueue &Q, int e)
{
    if ((Q.tail + 1) % Max_Size == Q.front) //判断是否已满
        return false;
    Q.base[(Q.tail++) % Max_Size] = e;
    // Q.base[Q.tail] = e;
    // Q.tail = (Q.tail + 1) % Max_Size;
    return true;
}

bool DeQueue(SqQueue &Q, int &e)
{
    if (Q.tail == Q.front) // 相遇证明已空
        return false;
    e = Q.base[(Q.front++ % Max_Size)];
    // e=Q.base[Q.front];
    // Q.front=(Q.front+1)%Max_Size;
    return true;
}

int QueueLength(SqQueue Q)
{
    return Q.tail - Q.front;
    // return (Q.tail-Q.front+Max_Size)%Max_Size;
}

int GetHead(SqQueue Q)
{
    if (Q.front != Q.tail)
        return Q.base[Q.front % Max_Size];
    // if (Q.front != Q.tail)
    //     return Q.base[Q.front];
    return -1;
}

main()
{
    SqQueue Q;
    int n, x;
    InitQueue(Q);
    puts("请输入元素个数n: ");
    scanf("%d", &n);
    puts("请依次输入n个整型数, 依次入队: ");
    while (n--)
    {
        scanf("%d", &x);
        EnQueue(Q, x);
    }
    puts("");
    printf("队列内元素个数, 即长度: %d\n", QueueLength(Q));
    printf("队头元素: %d\n", GetHead(Q));
    puts("元素依次出队: ");
    while (DeQueue(Q, x))
    {
        printf("%d\t", x);
    }
    puts("");
    printf("队列内元素个数, 即长度: %d\n", QueueLength(Q));
    return 0;
    //Over by:倪彬琪 QWQ
}
