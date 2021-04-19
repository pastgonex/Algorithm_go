// a,b,c 中, 1-9出现且仅出现一次
// 常数 ≈ 代码量
// n = a + b/c <----> cn = ac + b <----> b = cn - ca
// 1<=n<1e6 所以 n 最多只有 6 位 (999999)
// 枚举的过程中如果发现 a > n, 那么就可以退出
// 先枚举一下 a,然后再枚举c, ac确定了, b也就可以确定了,(对于每一个a,枚举一下c)--->判断 a b c 是否成立
// 把 a 的每一个叶子节点都扩展成一棵搜索树(枚举c)
// 搜完c 之后, 最后再判断一下 b是否成立
// long long 64bit  64*2^20byte==64M if开一个很大的数组, 但是不用的话,他是不会占用空间的
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

const int N = 1e1;

int n, ans;
bool st[N], backup[N];

bool check(int a, int c) {
    ll b = n * (ll) c - c * a; //因为 n*c 可能会溢出int从而变成负数, 所以使用long long
    if (!a || !b || !c) return false;
    memcpy(backup, st, sizeof backup);
    while (b) {
        int x = b % 10;
        b /= 10;
        if (!x || backup[x]) return false;
        backup[x] = true;
    }
    for (int i = 1; i <= 9; i++) {
        if (!backup[i]) return false;
    }
    return true;
}

void dfs_c(int u, int a, int c) {
    if (u == n) return;
    if (check(a, c)) ans++;
    for (int i = 1; i <= 9; i++) {
        if (!st[i]) {
            st[i] = true;
            dfs_c(u + 1, a, c * 10 + i); //此时 a 保持不变
            st[i] = false;
        }
    }
}

void dfs_a(int u, int a) // u表示当前已经用了几个数字
{
    if (a >= n) return;
    if (a) dfs_c(u, a, 0); // 只有 a>0 我们再往后做
    for (int i = 1; i <= 9; i++) {
        if (!st[i]) {
            st[i] = true;
            dfs_a(u + 1, a * 10 + i);
            st[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);

    dfs_a(0, 0);

    printf("%d\n", ans);
    return 0;
}
