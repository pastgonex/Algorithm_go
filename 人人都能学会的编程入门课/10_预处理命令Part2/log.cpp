#include "log.h"
#include <stdio.h>

void func(int a)
{
    log("a = %d\n", a);
}

int main()
{
    int a = 123;
    printf("a = %d\n", a);
    log("a = %d\n", a);
    func(a);
    return 0;
}
