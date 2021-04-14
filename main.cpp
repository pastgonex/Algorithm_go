#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 110;

int f[N];

int sg(int x)
{
    if (f[x] != -1) return f[x];        //若两个石堆中石子数相同，则它们的SG值也相同

    unordered_set<int> S;
    for (int i = 0; i < x; i ++ )
        for (int j = 0; j <= i; j ++ )  //新堆规模必须更小
            S.insert(sg(i) ^ sg(j));    //由SG函数理论，多个独立局面的SG值,等于这些局面SG值的异或和

    //mex操作
    for (int i = 0; ; i ++ )
        if (!S.count(i))
            return f[x] = i;            //当递归回第一层时，返回SG(x1)的值，即要用来异或的值
}

int main()
{
    int n;
    cin >> n;

    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 0; i < n; i ++ )       //n表示石子堆数量，x表示当前石子堆中石子数
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}
