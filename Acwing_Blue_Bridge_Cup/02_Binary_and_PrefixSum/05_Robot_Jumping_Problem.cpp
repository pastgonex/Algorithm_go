// N+1 座建筑, 编号0 - N
// 机器人在 第 K 个建筑, 现在的能量值是E
// 如果 H(k+1)>E  E = H(k+1)-E or 0
// else  E >= H(k+1)  E = 2E-h(k+1)  E = 2E - h(k+1) 一样
// todo 二段性
// 游戏目标是到达 第 N 个建筑(最后一个建筑)  E不能<0(E>=0)
// 求机器人最少需要多少能量值才可以完成游戏

#include <iostream>

const int N = 1e5 + 10;

int h[N];
int n;

bool check(int x) {
    for (int i = 0; i <= n; i++) {
        x = 2 * x - h[i];
        if (x >= 1e5)
            return true;
        if (x < 1)
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]); // h[1]-h[N];
    // E最大可以1e5 那么这样他就必然>=h[i]   1<=h[i]<=1e5  E最少需要1
    int l = 1, r = 1e5;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
