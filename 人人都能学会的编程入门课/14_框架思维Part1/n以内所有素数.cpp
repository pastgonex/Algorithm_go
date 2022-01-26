#include <cmath>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int st[N];

void init_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (st[i])
            continue;

        for (int j = i * 2; j <= n; j += i)
        {
            if (!st[j])
                st[j] = 1;
        }
    }
    return;
}

int main(void)
{
    scanf("%d", &n);
    init_prime(n);
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            if (i > 2)
                printf(" ");
            printf("%d", i);
        }
    }
    return 0;
}
