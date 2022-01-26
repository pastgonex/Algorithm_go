#include <cstdio>
#define MAX_N 10000
int prime[MAX_N + 5];

// 初始化素数表
void init_prime()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= MAX_N; i++)
    {
        if (prime[i])
            continue;
        for (int j = 2 * i; j <= MAX_N; j += i)
        {
            prime[j] = 1; // 将 j 标记为合数
        }
    }
    return;
}

int main()
{
    init_prime();
    int sum = 0;
    for (int i = 2; i <= MAX_N; i++)
    {
        sum += i * (1 - prime[i]); // 素数累加
    }
    printf("%d\n", sum);
    return 0;
}
