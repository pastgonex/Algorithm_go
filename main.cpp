//
// Created by Genes on 2020/10/29.
//
// X的因子链
// 数论

#include<cstdio>

typedef long long ll;

const int N = (1 << 20) + 10;

int primes[N];// 存质数
int min_p[N]; //存最小质因子
int cnt;
bool st[N]; // 表示对应元素是否被筛过

// 线性筛法(欧拉筛法)
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            min_p[i] = i;
            primes[++cnt] = i;
        }
        for (int j = 1; primes[j] * i <= n; j++) {
            int t = primes[j] * i;
            st[t] = true; //标记合数
            min_p[t] = primes[j];
            if (i % primes[j] == 0) {
                //如果i是前面某个素数的倍数时, 说明i以后会由某个更大的数乘这个小素数筛去
                //同理, 之后的筛数也是没有必要的, 因此在这个时候, 就可以跳出循环了
                break;
            }
        }
    }
}
int sum[N]; //记录每个质因子出现的次数

int main() {
    get_primes(N);
    int x;
    while (~scanf("%d", &x)) {
        //tol用于记录最大长度,k表示第i个质因子的下标, 从0开始
        int k = 0, tol = 0;

        // 依次处理各个质因子, 求出对应质因子出现的次数
        while (x > 1) {
            int p = min_p[x]; // 通过while, 依次取出最小质因子
            sum[k] = 0;

            //处理当前质因子, 求其出现的次数
            while (x % p == 0) {
                sum[k]++;
                tol++;
                x /= p;
            }
            k++; // 准备处理下一个质因子
            /*
             例:
                x=12 --> 3*2^2
                p = 2
                sum[1]=1
                x=6

                sum[1]=2
                x=3
                ****************
                p=3
                sum[2]=1
                x=1 --> 结束
             */
        }

        //求所有质因子出现总次数的全排列
        ll res = 1;
        for (int i = 2; i <= tol; i++) {
            res *= i; // tol!
        }
        //去除各个质因子重复出现的次数
        for (int i = 0; i < k; i++) {
            for (int j = 1; j <= sum[i]; j++) {
                res /= j;
            }
        }
        printf("%d %lld\n", tol, res); //输出最长序列的长度, 以及满足最大长度的序列的个数
    }
    return 0;
}