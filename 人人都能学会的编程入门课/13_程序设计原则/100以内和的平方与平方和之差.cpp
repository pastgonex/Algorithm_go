#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll sum_pow, pow_sum = 1;

int main(void)
{
    scanf("%d", &n);
    sum_pow = ((1 + n) * n / 2) * ((1 + n) * n / 2);
    //发现之间是一个等差数列
    //1+(1+3)+(1+3+5)+....+(1+3+5+.....an)

    int start = 1;
    int d = 2;
    int x = 1;
    int cur = start;
    for (int i = 2; i <= n; i++) // x 1+x+2 1+x+2+(x+2+2) 1+x+2+(1+2+2)+(1+2+2+2)
    {
        x += d;
        cur += x;
        pow_sum += cur;
    }
    printf("%lld\n", sum_pow - pow_sum);
    return 0;
}
