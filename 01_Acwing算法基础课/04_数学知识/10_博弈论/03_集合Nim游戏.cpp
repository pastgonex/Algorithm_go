#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

const int N = 110, M = 10010;
int n, m;
int f[M], s[N];  //s存储的是可供选择的集合,f存储的是所有可能出现过的情况的sg值

int sg(int x)
{
    if (f[x] != -1)
        return f[x];
    //因为取石子数目的集合是已经确定了的,所以每个数的sg值也都是确定的,如果存储过了,直接返回即可
    set<int> S;
    //set代表的是有序集合(注:因为在函数内部定义,所以下一次递归中的S不与本次相同)
    for (int i = 0; i < m; i++) {
        int sum = s[i];
        if (x >= sum)
            S.insert(sg(x - sum));
        //先延伸到终点的sg值后,再从后往前排查出所有数的sg值
    }

    for (int i = 0;; i++)
        //循环完之后可以进行选出最小的没有出现的自然数的操作
        if (!S.count(i))
            return f[x] = i;
}

int main()
{
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> s[i];

    cin >> n;
    memset(f, -1, sizeof(f));  //初始化f均为-1,方便在sg函数中查看x是否被记录过

    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res ^= sg(x);
        //观察异或值的变化,基本原理与Nim游戏相同
    }

    if (res)
        printf("Yes");
    else
        printf("No");

    return 0;
}