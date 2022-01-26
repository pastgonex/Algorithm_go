#include <iostream>

using namespace std;

int a;

int main(void)
{
    scanf("%d", &a);
    return 0;
}
//! 我们传给 scanf 函数的其实是 a变量的地址
//! 这样 scanf 函数就能把读入的数据传入a变量所对应的内存单元中
