#include <iostream>
using namespace std;
typedef long long LL;

const int N = 20;
int p[N], n, m;

int main()
{
    cin >> n >> m;

    // 读入n个质数
    for (int i = 0; i < m; i++)
        cin >> p[i];

    int res = 0;

    //枚举从1 到 1111...(m个1)的每一个集合状态, (至少选中一个集合)
    //从1开始枚举， 枚举到 2^m-1
    //一共有2^m-1项（除了一个都不选之外
    for (int i = 1; i < 1 << m; i++) {
        int t = 1;  //选中集合对应质数的乘积
        int s = 0;  //选中的集合数量 

        //枚举当前状态的每一位
        for (int j = 0; j < m; j++) {
            //选中一个集合
            if (i >> j & 1) {
                //乘积大于n, 则n/t = 0, 跳出这轮循环
                //当前质数的乘积就已经>n了， 直接跳出即可（
                if ((LL)t * p[j] > n) {
                    t = -1;
                    break;
                }
                s++;  //有一个1，集合数量+1
                t *= p[j];
            }
        }

        if (t == -1)
            continue;

        if (s & 1)
            res += n / t;  //选中奇数个集合, 则系数应该是1, n/t为当前这种状态的集合数量
        else
            res -= n / t;  //反之则为 -1
    }

    cout << res << endl;
    return 0;
}