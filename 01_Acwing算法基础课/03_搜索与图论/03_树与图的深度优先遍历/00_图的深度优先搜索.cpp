#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n, m;

// head, e[M],ne[M],idx; 是一条单链表
// h[N], e[M],ne[M],idx; 是N条单链表
int h[N], e[M], ne[M], idx;

bool st[N];  // 用st数组存一下哪些点已经被遍历过了

// 在a对应的单链表中插入一个节点b
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// u表示当前已经dfs到的这个点
void dfs(int u)
{
    st[u] = true;  // 标记一下， 当前这个点已经被搜索过了
    for (int i = h[i]; i != -1; i = ne[i]) {
        int j = e[i];  // 当前这个链表中的节点， 对应图中的点的编号是多少
        if (!st[j]) {
            dfs(j);
        }
    }
}

int main()
{
    // 一条单链表 head初始化为-1
    // n条单链表，把所有的head初始化为-1
    memset(h, -1, sizeof h);

    // 随便挑一个点， 比方说从第一个点开始搜
    dfs(1);

    return 0;
}
