#include <iostream>

using namespace std;

int main(void)
{
    int a = 123, *p = &a;
    printf("%d %p %d\n", a, p, *p);
    return 0;
}
