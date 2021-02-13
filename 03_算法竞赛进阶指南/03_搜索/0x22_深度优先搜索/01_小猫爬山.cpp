/*
 * Project: 0x22_深度优先搜索
 * File Created:Sunday, January 24th 2021, 11:31:12 am
 * Author: Bug-Free
 * Problem:AcWing 165. 小猫爬山
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e1;

int cat[N], cab[N];
int n, w;
int ans;

bool cmp(int a, int b)
{
    return a > b;
}

void dfs(int now, int cnt)
{
    if (cnt >= ans) {
        return;
    }
    if (now == n + 1) {
        ans = min(ans, cnt);
        return;
    }
    //尝试分配到已经租用的缆车上
    for (int i = 1; i <= cnt; i++) {  //分配到已租用缆车
        if (cab[i] + cat[now] <= w) {
            cab[i] += cat[now];
            dfs(now + 1, cnt);
            cab[i] -= cat[now];  //还原
        }
    }

    // 新开一辆缆车
    cab[cnt + 1] = cat[now];
    dfs(now + 1, cnt + 1);
    cab[cnt + 1] = 0;
}

int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }

    sort(cat + 1, cat + 1 + n, cmp);

    ans = n;

    dfs(1, 0);

    cout << ans << endl;

    return 0;
}
