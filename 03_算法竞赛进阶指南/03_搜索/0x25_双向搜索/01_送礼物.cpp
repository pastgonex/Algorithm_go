/*
 * File: 01_送礼物.cpp
 * Project: 0x25_双向搜索
 * File Created: Sunday, 10th March 2021 8:09:48 pm
 * Author: Bug-Free
 * Problem: AcWing 171. 送礼物
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 1 << 25;  // k最大是25， 因此最多可能有2^25种方案

int n, m, k;
int g[50];       // 存储所有物品的重量
int weights[N];  // weights存储能凑出来的所有的重量
int cnt = 0;
int ans;  // 用ans来记录一个全局最大值

// u表示当前枚举到哪个数了， s表示当前的和
void dfs(int u, int s)
{
    // 如果我们当前已经枚举完第k个数（下标从0开始的）了， 就把当前的s， 加到weights中去
    if (u == k) {
        weights[cnt++] = s;
        return;
    }

    // 枚举当前不选这个物品
    dfs(u + 1, s);

    // 选这个物品, 做一个可行性剪枝
    if ((LL)s + g[u] <= m) {  //计算和的时候转成long long防止溢出
        dfs(u + 1, s + g[u]);
    }
}

void dfs2(int u, int s)
{
    if (u == n) {  // 如果已经找完了n个节点， 那么需要二分一下
        int l = 0, r = cnt - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (weights[mid] <= m - s)
                l = mid;
            else
                r = mid - 1;
        }
        ans = max(ans, weights[l] + s);
        return;
    }

    // 不选择当前这个物品
    dfs2(u + 1, s);

    // 选择当前这个物品
    if ((LL)s + g[u] <= m)
        dfs2(u + 1, s + g[u]);
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];

    // 优化搜索顺序（从大到小）
    sort(g, g + n);
    reverse(g, g + n);

    k = n / 2 + 2;  // 把前k个物品的重量打一个表
    dfs(0, 0);

    // 做完之后， 把weights数组从小到大排序
    sort(weights, weights + cnt);

    // 判重
    int t = 1;
    for (int i = 1; i < cnt; i++)
        if (weights[i] != weights[i - 1])
            weights[t++] = weights[i];
    cnt = t;

    // 从k开始， 当前的和是0
    dfs2(k, 0);

    cout << ans << endl;

    return 0;
}
