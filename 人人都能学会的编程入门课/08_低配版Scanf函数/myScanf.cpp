#include <iostream>

using namespace std;

void myScanf(char *str, int *p)
{
    int num = 0, flag = 0;
    if (str[0] == '-')
        str += 1, flag = 1;
    for (int i = 0; str[i]; i++)
        num = num * 10 + (str[i] - '0');
    if (flag == 1)
        num = -num;
    *p = num;
}

int main(void)
{
    int n = 0;
    char str[100];
    scanf("%s", str); //读入字符串
    myScanf(str, &n);
    printf("%d\n", n);
    return 0;
}
