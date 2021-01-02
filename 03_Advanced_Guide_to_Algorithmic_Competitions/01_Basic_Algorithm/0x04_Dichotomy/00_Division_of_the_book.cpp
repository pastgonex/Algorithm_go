//
// Created by Genes on 2020/11/21.
//
// 有N本书排成一行, 已经第i本的厚度是Ai。
// 把他们分成连续的M组, 使T最小化, 其中T表示厚度之和最大的一组的厚度
/*
题目描述中出现了类似于"最大值最小"的含义, 这是答案具有单调性, 可用二分转化为判定的最常见、最典型的特征之一。
如果我们以"把书划分为M组的方案"作为定义域, "厚度之和最大的一组的厚度"作为评分(即值域), 需要最小化这个厚度值,
也就是评分越小越优。 相应的, 假设最终答案为S, 因为S的最优性，如果要求每组的厚度都＜S，那么这M组一定不能容纳这些书，
可能需要更多的组才能把书分完，也就意味着对于本题的限制条件不存在可行的分书方案。如果每组的厚度可以＞S，
那么一定存在一种分书方案使得组数不会超过M。
最优解就处于分书可行性的分界点上。
 */

#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N];
int n, m;

bool valid(int size) {
    int group = 1, rest = size; //每组的size
    for (int i = 1; i <= n; i++) {
        if (rest >= a[i]) { //如果放得下就继续放
            rest -= a[i];
        } else {// 放不下了就换一组新的
            group++, rest = size - a[i];
        }
    }
    return group <= m; // 返回group=m 或者 group<m 的前驱--> 要找最后一个<=m的数字
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int sum_of_ai = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum_of_ai += a[i];
    }
    // 二分答案, 判定"每组厚度之和不超过二分的值" 时
    // 能否在m组内把书分完
    int l = 0, r = sum_of_ai;
    while (l < r) {
        int mid = (l + r) / 2;
        if (valid(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}