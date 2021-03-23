#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int head[N], e[N], ne[N],idx;
int n, m;
int dist[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx++;
}

int bfs()
{
    queue<int> q;

    memset(dist, -1, sizeof dist);  // todo 初始化距离

    q.push(1);

    dist[1] = 0;  //? 最开始的时候 只有第一个点被遍历过了 他的距离是 0

    while (q.size()) {
        auto t = q.front();  // todo 每一次取得我们的队头
        q.pop();

        for (int i = head[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] == -1)  //!  如果 j 没有被扩展过
            {
                dist[j] = dist[t] + 1;
                q.push(j);
            }
        }
    }
    return dist[n];  //! 返回最后一个搜到的点的距离
}

int main()
{
    cin >> n >> m;

    memset(head, -1, sizeof head);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}