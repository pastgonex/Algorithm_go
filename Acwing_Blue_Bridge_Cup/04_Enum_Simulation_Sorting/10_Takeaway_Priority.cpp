//
// Created by Genes on 2020/9/26.
//
// 外卖店优先级

#include <cstdio>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m, T;
int score[N], last[N]; // score[i] 表示店铺 i的优先级, last[i]表示店铺上一次有订单的时间
bool st[N]; // st[i] 表示店铺i是否处于优先缓存

PII order[N];

int main() {
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &order[i].x, &order[i].y);
    }
    sort(order, order + m);

    for (int i = 0; i < m;) {
        //双指针
        int j = i;
        while (j < m && order[j] == order[i]) j++;
        int t = order[i].x, id = order[i].y, cnt = j - i;
        i = j;

        score[id] -= t - last[id] - 1;
        if (score[id] < 0) score[id] = 0;
        if (score[id] <= 3) st[id] = false; // 以上处理的是t时刻之前的信息

        score[id] += cnt * 2;
        if (score[id] > 5) st[id] = true;

        last[id] = t;
    }

    for (int i = 1; i <= n; i++)
        if (last[i] < T) {
            score[i] -= T - last[i];
            if (score[i] <= 3) st[i] = false;
        }

    int res = 0;
    for (int i = 1; i <= n; i++) res += st[i];

    printf("%d\n", res);

    return 0;
}