#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int head[N], e[N], ne[N], idx;
int d[N], top[N], cnt = 1;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx++;
}

int topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++) {  //将所有入度为0的点入队
        if (!d[i]) {
            q.push(i);
        }
    }

    while (q.size()) {
        int t = q.front();
        q.pop();
        top[cnt++] = t;

        for (int i = head[t]; i != -1; i = ne[i]) {
            int j = e[i];  //遍历t的所有出边
            d[j]--;        // j的入度-1
            if (!d[j]) {
                q.push(j);  // 如果j入度为0， 加入队列当中
            }
        }
    }

    return cnt >= n;
}

int main()
{
    memset(head, -1, sizeof head);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    if (topsort()) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                cout << " ";
            }
            cout << top[i];
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}