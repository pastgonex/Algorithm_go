#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3 + 10;

int n, m;
char g[N][N];
int dist[N][N];

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void bfs()
{
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '1') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }
            if (dist[x][y] == -1) {
                dist[x][y] = dist[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) {
                cout << " ";
            }
            cout << dist[i][j];
        }
        cout << endl;
    }

    return 0;
}