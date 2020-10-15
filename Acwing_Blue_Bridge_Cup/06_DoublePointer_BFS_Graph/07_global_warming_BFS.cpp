//
// Created by Genes on 2020/10/14.
//
// 全球变暖 BFS
#include<cstdio>
#include<algorithm>
#include<queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 10;

int n;
char g[N][N];
bool st[N][N];
bool path[N][N];

int dx[4] = {-1, 1, 0, 0}; //四个方位
int dy[4] = {0, 0, -1, 1};

void bfs(int sx, int sy, int &total, int &bound) {
    queue<pii> q;
    q.push({sx, sy});
    path[sx][sy] = true;
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        total++;
        bool is_bound = false;
        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= n) {
                continue;
            }
            if (path[x][y]) {
                continue;
            }
            if (g[x][y] == '.') {
                is_bound = true; //这个块是周围有海的块
                continue;
            }
            q.push({x, y});
            path[x][y] = true;
        }
        if (is_bound) {
            bound++; //当前岛屿总的周围有海的块的数量
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!path[i][j] && g[i][j] == '#') {
                int total = 0, bound = 0; //这个岛屿所有的块的数量, 这个岛屿上周围是海的块的数量
                bfs(i, j, total, bound);
                if (total == bound) { // 当前的块中所有的格子==周围有海洋的数量, 就会被淹没
                    cnt++;
                }
            }
        }
    }
    printf("%d\n", cnt);//被淹没的数量
    return 0;
}

