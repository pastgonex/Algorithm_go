#include <iostream>
#include <queue>

using namespace std;

int ver[10], tot, Next[10], head[10], deg[10], cnt, a[10];
int n, m;

void add(int x, int y)
{
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
    deg[y]++;
}

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
        while (q.size()) {
            int x = q.front();
            q.pop();
            a[++cnt] = x;
            for (int i = head[x]; i; i = Next[i]) {
                int y = ver[i];
                if (--deg[y] == 0) {
                    q.push(y);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;  //点数， 边数
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    topsort();
    for (int i = 1; i <= cnt; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
