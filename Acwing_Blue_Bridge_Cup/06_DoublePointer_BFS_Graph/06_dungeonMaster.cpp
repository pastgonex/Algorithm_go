//
// Created by Genes on 2020/10/14.
//
// 地牢大师
// BFS 广度优先搜索

#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

const int N = 1e2 + 10;

char g[N][N][N];
int l, r, c; //层数, 行数, 列数
int path[N][N][N];//判重数组

int dx[6] = {0, 1, 0, -1, 0, 0}; //东南西北上下
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Point {
    int x, y, z;
};

int bfs(Point start, Point end) {
    queue<Point> q;
    q.push(start);
    memset(path, -1, sizeof path);
    path[start.x][start.y][start.z] = 0;
    while (!q.empty()) {
        Point t = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int x = t.x + dx[i], y = t.y + dy[i], z = t.z + dz[i];
            if (x < 0 || x >= l || y < 0 || y >= r || z < 0 || z >= c) { //层, 行, 列
                continue;
            }
            if (path[x][y][z] != -1) {
                continue;
            }
            if (g[x][y][z] == '#') {
                continue;
            }
            path[x][y][z] = path[t.x][t.y][t.z] + 1;
            if (end.x == x && end.y == y && end.z == z) {
                return path[x][y][z];
            }
            q.push({x, y, z});
        }
    }
    return -1;
}

int main() {
    while (cin >> l >> r >> c, l || r || c) { // 层数, 行数, 列数
        Point start, end;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                scanf("%s", g[i][j]);
                for (int k = 0; k < c; k++) {
                    char t = g[i][j][k];
                    if (t == 'S') {
                        start = {i, j, k};
                    } else if (t == 'E') {
                        end = {i, j, k};
                    }
                }
            }
        }
        int distance = bfs(start, end);
        if (distance == -1) {
            puts("Trapped!");
        } else {
            printf("Escaped in %d minute(s).\n", distance);
        }
    }
    return 0;
}


