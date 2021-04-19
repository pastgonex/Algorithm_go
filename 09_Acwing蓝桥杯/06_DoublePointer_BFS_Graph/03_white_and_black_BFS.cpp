//
// Created by Genes on 2020/10/12.
//
// 红与黑

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

const int N = 2e1 + 5;

int n, m;
char g[N][N];
int path[N][N];

int bfs(pii start) {
    int cnt = 1;
    queue<pii> q;
    memset(path, -1, sizeof path);
    path[start.first][start.second] = 0;
    q.push(start);
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) {
                continue;
            }
            if (g[a][b] == '#') {
                continue;
            }
            if (path[a][b] != -1) {
                continue;
            }
            path[a][b] = path[t.first][t.second] + 1;
            q.push(make_pair(a, b));
            cnt++;
        }
    }
    return cnt;
}

int main() {
    while (cin >> m >> n, n || m) {
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }
        pii start;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '@') {
                    start = {i, j};
                    break;
                }
            }
        }
        printf("%d\n", bfs(start));
    }
    return 0;
}

