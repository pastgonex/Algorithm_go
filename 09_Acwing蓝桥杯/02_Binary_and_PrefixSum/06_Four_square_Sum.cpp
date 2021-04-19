// 拉格朗日定理 - 四平方和定理
// 任何一个正整数都可以由 4个整数的平方和
// 同样一个正整数, 可能存在多种方案
// a, b, c, d 按照一个递增的顺序进行排序, 输出最小的
// N <= 5e6
// a,b,c,d 都是<=N^1/2  每个数 0<= x <= 2200 左右
// 所以最多枚举2个数, 2200^2 , 三个数就 2200^3 = 8e9 所以最多2个
// 1. 最多只能枚举两个数
// 2. 如果可以枚举三个数 d = (N-a^2-b*2-c^2)^1/2
// 3. 所以需要考虑使用空间来换取时间
// 4. 本来需要枚举三重循环
/*
for(a)
    for(b)
        for(c)
*/
/*
for(c)
    for(d=c;c^2+d^2<=N;d++)  先把两重循环的结果存下来
    然后把所有的c^2+d^2存起来
    然后再枚举 a 和 b

for(a)
    for(b=a;a^2+b^2<=n;b++)
    {
        int d = n-a^2-b^2;
        if (check(d)) ok
        else continue;
    }
check(d) 的时候可以二分
*/

// todo 补充一个语法 [运算符重载]
// todo 语法: 返回值类型 operator op(参数);

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 25e5 + 10;

struct Sum {
    int s, c, d;                       // s表示c和d的平方
    bool operator<(const Sum &t) const //返回较小的那个
    {
        if (s != t.s)
            return s < t.s;
        if (c != t.c)
            return c < t.c;
        return d < t.d;
    }
} sum[N];

// bool cmp(struct Sum &a, struct Sum &b)
// {
//     if (a.s < b.s)
//         return a.s < b.s;
//     if (a.c < b.c)
//         return a.c < b.c;
//     return a.d < b.d;
// }

int n, m;

int main() {
    scanf("%d", &n);

    for (int c = 0; c * c <= n; c++)
        for (int d = c; c * c + d * d <= n; d++)
            sum[m++] = {c * c + d * d, c, d};

    // sort(sum, sum + m, cmp);
    sort(sum, sum + m);

    for (int a = 0; a <= n; a++)
        for (int b = 0; b * b + a * a <= n; b++) {
            int t = n - a * a - b * b;
            int l = 0, r = m - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (sum[mid].s >= t) //要找一个最小的 所以是>=
                    r = mid;
                else
                    l = mid + 1;
            }
            if (sum[l].s == t) {
                printf("%d %d %d %d\n", a, b, sum[l].c, sum[l].d);
                return 0;
            }
        }
    return 0;
}
