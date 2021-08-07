#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];
int n;

// 筛出1~n中所有的质数
void get_primes(int n)
{
    for (int i = 2; i <= n; i++) {
        // if (!st[i]) {
        //     primes[cnt++] = i;

        // 朴素筛法
        // 筛掉这个质数的所有倍数（质数定理：所有质数的倍数都是合数）
        // for (int j = i + i; j <= n; j += i) {
        //     st[j] = true;
        // }

        // 埃氏筛法
        // 小于 x^2的x的倍数在扫描更小的数时就已经被标记过了.
        // 因此， 对于每个数x， 我们只需要从x^2 开始， 吧x^2, (x+1)x, ...(N/x)*x 标记为合数即可
        // for (int j = i; j <= n / i; j++) {
        //     st[i * j] = true;
        // }

        // 线性筛法
        // 一个合数 x 只会被他的最小质因子筛掉
        // 当 i % primes[j] ==0 --> primes[j] 一定是i的最小质因子，      primes[j]也一定是primes[j]*i的最小质因子
        // 当 i % primes[j] !=0 --> primes[j] 一定小于i的所有最小质因子， primes[j]也一定是primes[j]*i的最小质因子
        // 每个合数都是通过最小质因子来筛， 每个数只有一个最小质因子， 因此是 O(N)
        if (!st[i]) {
            primes[cnt++] = i;
        }

        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;  // primes[j]一定是 primes[j]*i 的最小质因子
            if (i % primes[j] == 0) {  // 此时primes[j] 一定是i的最小质因子（从小到大枚举所有质数，第一次 %primes[j]==0
                break;
            }
        }
    }
}

int main()
{
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}