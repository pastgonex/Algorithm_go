#include <cstdio>

// 打印一个素因子，并且在中间输出 * 乘号
void print_num(int num, int *flag)
{
    if (*flag == 1)
        printf(" * ");
    printf("%d", num);
    *flag = 1;
    return;
}

int main()
{
    int n, i = 2, flag = 0, raw_n;
    scanf("%d", &n);
    raw_n = n;
    // 循环终止条件，循环到 n 的平方根结束
    while (i * i <= n)
    {
        //①：只要 n 可以被 i 整除，就认为 i 是 n 的一个素因子
        while (n % i == 0)
        {
            print_num(i, &flag);
            n /= i;
        }
        i += 1;
    }
    //②：如果最后 n 不等于 1，就说明 n 是最后一个素数
    if (n != 1)
        print_num(n, &flag);
    printf(" = %d\n", raw_n);
    return 0;
}
