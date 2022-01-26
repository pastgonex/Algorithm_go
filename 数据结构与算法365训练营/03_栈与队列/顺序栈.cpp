#include <iostream>

using namespace std;

#define DataType int

const int MaxSize = 100; //预先分配空间, 根据实际需要

typedef struct SqStack
{
    DataType *base; //栈底指针
    DataType *top;  //栈顶指针
} SqStack;

bool InitStack(SqStack &S) //构造一个空栈 S
{
    S.base = new int[MaxSize];
    if (!S.base) //空间分配失败
        return false;
    S.top = S.base; //top初始化为base, 空栈
    return true;
}

bool Push(SqStack &S, int e)
{
    if (S.top - S.base == MaxSize) //栈满
        return false;
    *(S.top++) = e; //元素e压入栈顶, 然后栈顶指针向上一格
    return true;
}

bool Pop(SqStack &S, int &e)
{
    if (S.base == S.top) //栈空
        return false;
    e = *(--S.top); //栈顶指针-1, 然后取值
    return true;
}

int GetTop(SqStack S)
{
    if (S.top != S.base) //不空
        return *(S.top - 1);
    else
        return -1;
}

int main(void)
{
    int n, x;
    SqStack S;
    InitStack(S); //初始化一个顺序栈
    puts("请输入元素个数n: ");
    scanf("%d", &n);
    puts("请依次输入n个元素, 依次入栈: ");
    while (n--)
    {
        scanf("%d", &x);
        Push(S, x);
    }
    puts("元素依次出栈: ");
    while (S.top != S.base) //如果栈不空, 则依次出栈
    {
        printf("%d\t", GetTop(S));
        Pop(S, x); //栈顶元素出栈
    }
    return 0;
}
