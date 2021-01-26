#include <iostream>
#include<cstring>
#include<queue>

using namespace std;

int d[10];
int head[10],Next[10],ver[10];

void bfs() {
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (q.size() > 0) {
        int x = q.front();
        q.pop(); for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if (d[y]) {
                continue;
            }
            d[y] = d[x] + 1;
            q.push(y);
        }
    }
}
