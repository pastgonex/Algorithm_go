/*
 * Project: 0x21_树与图的遍历
 * File Created:Tuesday, January 26th 2021, 7:31:09 pm
 * Author: Bug-Free
 * Problem:Acwing 164. 可达性统计
 */
#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 3e4 + 10;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N], seq[N];  //入度， 拓扑序列

bitset<N> f[N];

void add(int a, int b)
{
    e[idx]  = b;
    ne[idx] = h[a];
    h[a]    = idx++;
}

// 只有有向无环图， 才能做拓扑排序
// 拓扑排序
void topsort()
{
    queue<int> q;

    // 先把所有入度为 0 的点加入队列（有向图）
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            q.push(i);
        }
    }
    // k表示当前拓扑排序中元素的个数
    int k = 0;
    while (q.size()) {
        int t = q.front();
        q.pop();
        seq[k++] = t;  //将队头元素加入拓扑序中
        //将当前点可以到的点的入度--（删去x连向其他点的边）
        for (int i = h[t]; ~i; i = ne[i]) {  // 遍历这个点所有的邻边
            int j = e[i];                    // e[i] 表示 邻边所对应的终点
            if (--d[j] ==
                0) {  //如果j这个点的入度为0了，那我们就可以加到队列中去
                q.push(j);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;  //有一条 a 指向 b的边， 因此b的入度+1
    }

    topsort();

    // 从后往前递推
    // bitset<N> s;
    // s[k] 表示 第k位， 既可以取值， 也可以赋值
    for (int i = n - 1; i >= 0; i--) {
        int j   = seq[i];
        f[j][j] = 1;                         // j这个点可以到达自己   f[j][j] =表示从 j出发的点，
                                             // 能够到的点（1表示可以到， 0表示不能到），j可以到自己，
                                             // 因此f[j][j]=1
        for (int k = h[j]; ~k; k = ne[k]) {  //所有能到到达的点
            f[j] |= f[e[k]];                 // j这个点可以到达的点的数量= {j} U {y1} U {y2}
                                             // ... {yn}
        }
    }
    for (int i = 1; i <= n; i++) {
        // f[i].count() 返回f[i] 中 1的个数
        cout << f[i].count() << endl;
    }
    return 0;
}
