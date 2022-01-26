#include <iostream>

using namespace std;

int square(int x)
{
    return x * x;
}

int main(void)
{
    int n; // n变量与 函数中的x是相互独立的, 函数改变不了n的值, 除非n是全局的
    scanf("%d", &n);
    printf("%d\n", square(n));
    return 0;
}
