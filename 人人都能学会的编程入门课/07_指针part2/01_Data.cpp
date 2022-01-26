#include <iostream>

using namespace std;

struct Date
{
    int x, y;
} a[2];

int main(void)
{
    struct Date *p = a;
    printf("%p\n", &a[1].x);
    printf("%p\n", &(a + 1)->x);   // 方法1, 效果和上面一样
    printf("%p\n", &(a[0].y) + 1); // 定位到 a[0].y, 然后+1就是a[1].x的地址了
    printf("%p\n", &(p + 1)->x);
    printf("%p\n", &(p->y) + 1);
    printf("%p\n", &(p + 1)->y - 1);
    printf("%p\n", &(p->x) + 2);
    printf("%p\n", &(p)->x + 2);
    return 0;
}
