#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 5e2 + 10, M = 1e5 + 10;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i]) {  // 枚举这个男生所有看上的妹子
        int j = e[i];
        if (!st[j]) {  // 如果这个妹子之前没有考虑过
            st[j] = true;
            if (match[j] == 0 || find(match[j])) {  // 妹子单身 或 虽然匹配了男生，但是这个男生有备胎
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st);  // 先把所有妹子清空， 表示这些都没有考虑过
        if (find(i)) {
            res++;  // 如果找打了妹子， 答案++
        }
    }
    cout << res << endl;
    return 0;
}