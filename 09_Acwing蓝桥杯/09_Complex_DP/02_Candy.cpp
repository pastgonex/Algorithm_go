//
// Created by Genes on 2020/11/13.
//
// 糖果
// Dp  01背包问题

/*
 状态表示:
    集合: 所有的从i个物品中选, 且选出的糖数的总和%k==j的所有方案的集合
    属性: f(i,j) =最大值

 状态计算:(划分的依据是所有方案是所有方案的最后一个不同点)
    如何计算划分的集合?
        从实际含义出发(状态表示中的集合)
    不包含物品i的集合: f(i-1,j)
    包含物品i的集合: f(i-1,(j-wi)%k+wi)    --> 这里需要注意负数取模==0|负数  优化-> (j+k-wi%k)%k
    最终是: f(i,j)=max(f(i-1,j),f(i-1,(j-wi)%k+wi))
 */

#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e2 + 10;

int n, k;
int f[N][N];

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    cin >> n >> k;

    memset(f, -0x3f, sizeof f); //初始化为 -∞

    f[0][0] = 0; //只有f[0][0]是有意义的

    for (int i = 1; i <= n; i++) {
        int w;
        cin >> w;
        //余数一定是 0 - k-1 的
        for (int j = 0; j < k; j++) {
//            f[i][j] = max(f[i - 1][j], f[i - 1][(j - w) % k] + w);  后半部分 要考虑c++中的取模运算, 负数取模是0或者负数
//                                                                    可以改成
            f[i][j] = max(f[i - 1][j], f[i - 1][(j + k - w % k) % k] + w);
        }
    }
    // 答案是从n个数中选, %k 余数为0的最大值
    cout << f[n][0] << endl;
    return 0;
}