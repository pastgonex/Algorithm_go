#include <cstdio>

typedef long long ll;

ll fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld\n", fibonacci(n));
    return 0;
}
