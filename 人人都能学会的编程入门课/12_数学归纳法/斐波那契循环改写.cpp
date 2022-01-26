#include <cstdio>

typedef long double ld;

int n;
ld first = 1, second = 1;

int main(void)
{
    scanf("%d", &n);
    if (n == 1 || n == 2)
        puts("1");
    else
    {
        for (int i = 3; i <= n; i++)
        {
            second = first + second;
            first = second - first;
        }
        printf("%.0Lf\n", second);
    }
    return 0;
}
