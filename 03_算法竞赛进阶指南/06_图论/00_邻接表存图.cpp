#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int head[N], e[N], ne[N], idx;
int edge[N];

void add(int x, int y, int z)
{
    e[idx] = y;
    edge[idx] = z;
    ne[idx] = head[x];
    head[x] = idx++;
}

int main()
{
    int x = 1;
    for (int i = head[x]; i != -1; i = ne[i]) {
        int j = e[i], z = edge[i];
        // 找到了一条有向边（x,y)， 权值为z
    }
}
