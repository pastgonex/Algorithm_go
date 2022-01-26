#include <iostream>

using namespace std;

int main(void)
{
    int a, *p = &a;
    char *q = (char *)&a;
    printf("%p %p\n", p, q);       // int和char指针刚开始是一样的, 都是a的首地址
    printf("%p %p", p + 1, q + 1); //int类型的指针+1之后差了4个字节, char类型的+1之后差了1个字节
    return 0;
}
