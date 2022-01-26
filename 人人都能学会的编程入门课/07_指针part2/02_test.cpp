#include <iostream>

using namespace std;

int main(void)
{
    int a = 0x61626364;
    int *p = &a;
    char *q = (char *)&a;
    printf("%x %c\n", *p, *q); // %x读入16进制整数 %c读入一个字符
    return 0;
}
