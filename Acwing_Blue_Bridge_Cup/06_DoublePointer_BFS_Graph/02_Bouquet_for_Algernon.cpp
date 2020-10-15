//
// Created by Genes on 2020/10/11.
//
// 献给阿尔吉侬的花束
// BFS
/*
todo
 我们借助一个队列来实现广度优先搜索(BFS):
    起初队列中只包含起始状态 --> q.push(start);
    对于该状态面临的所有的分支, 把沿着每条分支到达的下一个状态(如果尚未访问或者能够被更新成更优的解)插入队尾。 重复执行操作执行队列为空

    队列---> 先进先出
    理论上同时进行, 但是程序不行, 所以只能使用队列, 一个一个来
    最后走到终点的"分身" 报告路径长度

    将起始点扩展的状态压入队列, 模拟一个同时走的过程, 那么第一个走到终点的就是答案
    例如 起始点扩展了a b c 三个状态, 那么a先走,扩展了k个状态, 并且把k个状态压入队列 --> b c ai-ak
    然后 b再走 同理 c再走  这样就是一个排队的过程 -->  ai-ak bi-bk ci-ck   每次都是走一步
    那么先到终点的必然是最短路径
 */

#include<iostream>
#include<cstring>
#include<queue>

#define x first
#define y second

using namespace std;

const int N = 2e2 + 10;

typedef pair<int, int> pii;

int path[N][N];
int n, m;
char g[N][N];
int T;

int bfs(pii start, pii end) {
    queue<pii> q;
    memset(path, -1, sizeof path); //-1表示没有走过
    path[start.x][start.y] = 0; //表示起始点, 路径长度为0
    q.push(start); //把初始状态压入队列

    // 小技巧
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    while (!q.empty()) { //只要队列不空 --> 还有路可走
        pii t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#' || path[a][b] != -1) {
                continue;
            }
            path[a][b] = path[t.x][t.y] + 1;
            if (end == make_pair(a, b)) {
                return path[a][b];
            }
            q.push({a, b});
        }
    }
    return -1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }
        pii start, end;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'S') {
                    start = {i, j};
                } else if (g[i][j] == 'E') {
                    end = {i, j};
                }
            }
        }
        int distance = bfs(start, end);
        if (distance == -1) {
            puts("oop!");
        } else {
            printf("%d\n", distance);
        }
    }
    return 0;
}