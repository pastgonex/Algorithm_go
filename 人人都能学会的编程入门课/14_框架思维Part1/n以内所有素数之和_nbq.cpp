#include <cmath>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

typedef long long ll;

int st[N];
int n;
ll sum;

void init_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (st[i])
            continue;
        for (int j = i * 2; j <= n; j += i)
        {
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
        sum += i * (!st[i]);
    printf("%d\n", sum);
    return 0;
}
