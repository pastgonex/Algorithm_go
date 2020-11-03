#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
# define ll long long
# define read read1<int>()
# define Type template<class T>

Type T read1() {
    T t = 0;
    bool vis = 0;
    char k;
    do (k = getchar()) == '-' && (vis = 1); while ('0' > k || k > '9');
    while ('0' <= k && k <= '9')t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
    return vis ? -t : t;
}

# define ll long long
int a, b, h, w, s, v[100005];
pair<ll, ll> x[1 << 18];

bool dfs(int o, int p, int n) {
    int tot = 0, nx = n >> 1, ny = n - nx;
    for (int i = 0; i < (1 << nx); ++i) {
        x[i].first = 1;
        x[i].second = 1;
        for (int j = 0; j < nx; ++j)
            if ((i >> j) & 1)
                x[i].second *= v[j + 1];
            else x[i].first *= v[j + 1];
    }
    sort(x, x + (1 << nx));
    for (int i = 0; i < (1 << ny); ++i) {
        ll wx = 1, wy = 1;
        for (int j = 0; j < ny; ++j)
            if ((i >> j) & 1)
                wy *= v[j + nx + 1];
            else wx *= v[j + nx + 1];
        pair<ll, ll> *we = lower_bound(x, x + (1 << nx), make_pair((a - 1) / (o * wx) + 1, (b - 1) / (p * wy) + 1));
        if (we != x + (1 << nx) + 1 && we->second >= (b - 1) / (p * wy) + 1)return 1;
    }
    return 0;
}

int main() {
    cin >> a >> b >> h >> w >> s;
    for (int i = 1; i <= s; ++i)v[i] = read;
    sort(v + 1, v + s + 1);
    reverse(v + 1, v + s + 1);
    for (int i = 0; i <= s; ++i)
        if (dfs(h, w, i) || dfs(w, h, i))
            return printf("%d", i), 0;
    puts("-1");
    return 0;
}
