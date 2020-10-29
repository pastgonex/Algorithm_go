//
// Created by Genes on 2020/10/28.
//
// 灵能传输
// 贪心

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 3e5 + 10;

//由于a[]可能达到1e9所以需要使用到LL
typedef long long LL;

LL a[N];    //用于存放初始灵能值
LL s[N];    //用于存放前缀和
LL f[N];    //用于存放最终的有序序列

bool st[N];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        s[0] = 0;// 注意这一步不要忘了

        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i];


        LL s0 = s[0], sn = s[n];

        if (s0 > sn)
            swap(s0, sn);

        sort(s, s + 1 + n);

        //找到排序后 s0,sn的位置
        for (int i = 0; i <= n; i++)
            if (s0 == s[i]) {
                s0 = i;
                break;
            }

        for (int i = 0; i <= n; i++)
            if (sn == s[i]) {
                sn = i;
                break;
            }

        memset(st, false, sizeof st);

        //构造重叠部分最小的序列

        int l = 0, r = n;

        for (int i = s0; i >= 0; i -= 2)
            f[l++] = s[i], st[i] = true;

        for (int i = sn; i <= n; i += 2)
            f[r--] = s[i], st[i] = true;

        for (int i = 0; i <= n; i++)
            if (st[i] == false)
                f[l++] = s[i];

        LL res = 0;

        for (int i = 1; i <= n; i++)
            res = max(res, abs(f[i] - f[i - 1]));

        printf("%lld\n", res);

    }

    return 0;
}