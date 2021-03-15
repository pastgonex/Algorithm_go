#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e2 + 10;

int n, m;
int g[N][N], dist[N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int bfs()
{
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof dist);
    dist[0][0] = 0;
    q.push({0, 0});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == 1 || dist[x][y] != -1) {
                continue;
            }
            dist[x][y] = dist[t.first][t.second] + 1;
            q.push({x, y});
        }
    }
    return dist[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}