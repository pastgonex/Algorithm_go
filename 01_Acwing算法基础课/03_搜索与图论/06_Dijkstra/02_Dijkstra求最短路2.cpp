#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e6 + 10;

typedef pair<int, int> pii;

int n, m;
int head[N], e[N], ne[N], idx, w[N];
int dist[N];  //从1号点走到每个点， 当前的最短距离是多少
bool st[N];  //用于在更新最短距离时，判断当前的点的最短距离是否确定，是否需要更新

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = head[a];
    head[a] = idx++;
}

// 进行n次迭代后最后就可以确定每个点的最短距离
// 然后再根据题意输出相应的 要求的最短距离
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;  // 第一个点到自己的距离为0

    priority_queue<pii, vector<pii>, greater<pii>> heap;  //转换为小根堆

    heap.push({0, 1});  //将1号点放进来， 值是0， 编号是1

    while (heap.size()) {
        auto t = heap.top();  //每次找到堆中最小的点
        heap.pop();
        int ver = t.second, distance = t.first;  //距离最小的点的编号和距离

        if (st[ver]) {  //如果这个点被访问过， 就continue
            continue;
        }

        st[ver] = true;

        // 更新当前这个点的所有出边
        for (int i = head[ver]; i != -1; i = ne[i]) {
            int j = e[i];  // 找到第i条边指向的点
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) {  // 如果第n个点路径为无穷大即不存在最低路径
        return -1;
    }
    return dist[n];
}

int main()
{
    cin >> n >> m;

    memset(head, -1, sizeof head);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);  //用邻接表存， 重边就无所谓了
    }

    // 求单源最短路径
    cout << dijkstra() << endl;

    return 0;
}