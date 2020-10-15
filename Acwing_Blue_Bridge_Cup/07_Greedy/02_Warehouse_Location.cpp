//
// Created by Genes on 2020/10/16.
//
// 货仓选址
/*
    猜想:
     1. 奇数个点(中位数上)
     2. 偶数个点(中间两个之间==(中间两个任意一个))

    如何证明:
        推公式:
            先用公式形式化表示, 看一下公式的最大值是多少
                假设每个上商店的坐标分别是xi 1<=i<=n
                最终仓库的位置是c
                每一个仓库和c的距离是 |c-x[i]|
        目标是所有绝对值的和: i从1到n |x[i]-c|的和最小
        |x[1]-c|+|x[2]-c|+|x[3]-c|+...+[x[n]-c| 最小--> 求等式最小值
        分组:
           第一组:  |x[1]-c|+|x[n]-c|   --> 几何意义(绝对值不等式)  只要c在x[1]和x[n]之间 就可以取到最小值
           第二组:  |x[2]-c|+|x[n-1]-c|  同理--> 在x[2]和x[n-1]之间 就可以取到最小值
           ....
           奇数:    |x[中]-c|
           偶数:    |x[中间两个]-c|

        结论: c在中间(分奇数和偶数), 则每一组均取最小值
 */

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n;
int x[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + 1 + n);
    ll distance = 0;
    int c = x[n + 1 >> 1];
    for (int i = 1; i <= n; i++) {
        distance += abs(x[i] - c);
    }
    cout << distance << endl;
    return 0;
}