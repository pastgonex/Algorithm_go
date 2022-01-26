#include <iostream>

using namespace std;

const int N = 1010;

int n;
int f[N];

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        f[i] = f[i & (i - 1)] + 1;

    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", f[i]);
    }
    return 0;
}
