//
// Created by Genes on 2020/10/11.
//
// 红蓝按钮
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 50;
int n, m;
int st[N];

void bfs(int n, int m) {
    queue<int> q;
    q.push(n);
    st[n] = 1;
    while (q.size()) {
        int t = q.front();
        q.pop();
        if (t == m)
            break;
        if (t > 1 && st[t - 1] == 0) {
            st[t - 1] += st[t] + 1;
            q.push(t - 1);
        }
        if (t <= 1e4 && st[t << 1] == 0) {
            st[t << 1] += st[t] + 1;
            q.push(t << 1);
        }
    }
}

int main() {
    cin >> n >> m;
    bfs(n, m);
    cout << st[m] - 1 << endl;
}
