#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 5e2 + 10;

struct State
{
    int x, y, lie;
};

int n, m;
char g[N][N];
int dist[N][N][3];

// 辅助函数， 判断是否出界
bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return g[x][y] != '#';  //判断该点是否是 禁地（空的
}

int bfs(State start, State end)
{
    queue<State> q;
    memset(dist, -1, sizeof dist);
    dist[start.x][start.y][start.lie] = 0;
    q.push(start);

    // 3种状态（横，竖，立）
    // 四个方向（上右下左)
    // 3表示一共有3种状态需要改变
    int d[3][4][3] = {
        {{-2, 0, 2}, {0, 1, 1}, {1, 0, 2}, {0, -2, 1}},   // 0立着
        {{-1, 0, 1}, {0, 2, 0}, {1, 0, 1}, {0, -1, 0}},   // 1横着
        {{-1, 0, 0}, {0, 1, 2}, {2, 0, 0}, {0, -1, 2}}};  // 2竖着

    while (q.size()) {
        auto t = q.front();
        q.pop();

        // 扩展t
        // 枚举4个方向
        for (int i = 0; i < 4; i++) {
            State next;                                                           //下一个扩展的点
            next = {t.x + d[t.lie][i][0], t.y + d[t.lie][i][1], d[t.lie][i][2]};  //x和y的偏移量+直接变成的状态

            int x = next.x, y = next.y;

            if (!check(x, y)) {
                continue;
            }
            if (next.lie == 0 && g[x][y] == 'E') {  //站在脆弱的格子上
                continue;
            }
            if (next.lie == 1 && !check(x, y + 1)) {
                continue;
            }
            if (next.lie == 2 && !check(x + 1, y)) {
                continue;
            }

            if (dist[x][y][next.lie] == -1) {  //如果这个状态没有被搜索过， 我们才会去拓展他
                dist[x][y][next.lie] = dist[t.x][t.y][t.lie] + 1;
                q.push(next);
            }
        }
    }
    return dist[end.x][end.y][end.lie];
}

int main()
{
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }

        State start = {-1}, end;

        // 遍历每一个点
        // 立着 0
        // 横着 1
        // 竖着 2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'X' && start.x == -1) {
                    if (g[i + 1][j] == 'X') {  // 竖着
                        start = {i, j, 2};
                    }
                    else if (g[i][j + 1] == 'X') {
                        start = {i, j, 1};  //横着
                    }
                    else {  //立着
                        start = {i, j, 0};
                    }
                }
                else if (g[i][j] == 'O') {
                    end = {i, j, 0};  //最后一定是立上去的->终点
                }
            }
        }
        int res = bfs(start, end);  // bfs从起点搜到终点
        if (res == -1) {
            puts("Impossible");
        }
        else {
            printf("%d\n", res);
        }
    }
    return 0;
}