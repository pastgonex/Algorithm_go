#include <iostream>

using namespace std;

struct point
{
    int x, y;
};

int main(void)
{
    struct point p1, p2;
    p1.x = 2, p1.y = 3;
    p2.x = 7, p2.y = 7;
    printf("%d\n", sizeof(p1));
    printf("%d\n", sizeof(point));
    return 0;

}
