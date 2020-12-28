#include <limits.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010, M = 7000010;

int n, m, q, u, v, t;
int q1[N], q2[M], q3[M];
int delta;
int hh1, hh2, hh3, tt1, tt2 = -1, tt3 = -1;

int get_max() {
    int x = INT_MIN;
    if (hh1 <= tt1)
        x = max(x, q1[hh1]);
    if (hh2 <= tt2)
        x = max(x, q2[hh2]);
    if (hh3 <= tt3)
        x = max(x, q3[hh3]);
    if (hh1 <= tt1 && x == q1[hh1])
        hh1++;
    else if (hh2 <= tt2 && x == q2[hh2])
        hh2++;
    else
        hh3++;
    return x;
}

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
    for (int i = 0; i < n; i++)
        scanf("%d", &q1[i]);
    sort(q1, q1 + n);
    reverse(q1, q1 + n);
    tt1 = n - 1;
    double p = (double)u / v;
    for (int i = 1; i <= m; i++) {
        int x = get_max();
        x += delta;
        if (i % t == 0)
            printf("%d ", x);
        int left = x * 1ll * p;
        int right = x - left;
        delta += q;
        left -= delta, right -= delta;
        q2[++tt2] = left, q3[++tt3] = right;
    }
    puts("");

    for (int i = 1; i <= n + m; i++) {
        int x = get_max();
        if (i % t == 0)
            printf("%d ", x + delta);
    }
    puts("");
    return 0;
}
