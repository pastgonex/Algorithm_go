//
// Created by Genes on 2020/12/19.
//
// 火车进栈 dfs

// 面对任何一个状态, 我们只有两种选择:
// 1. 把下一个数进栈
// 2. 把当前栈顶的数出栈(如果栈非空)

#include<iostream>
#include<vector>

using namespace std;

const int N = 2e1 + 5;

int n, remain = 0;
int tt, stk[N];
vector<int> path;

void dfs(int u) {
    if (u == n + 1) { // edge
        if (++remain > 20) {
            exit(0);
        }
        for (auto x:path) { //输出路径中的
            cout << x;
        }
        // 如果没有数字可用了, 那么输出一下path+栈中的数字
        for (int i = tt - 1; i >= 0; i--) { //输出栈中剩下的(后进先出
            cout << stk[i];
        }
        cout << endl;
        return;
    }
    if (tt) {
        path.push_back(stk[--tt]);
        dfs(u);
        stk[tt++] = path.back();
        path.pop_back();
    }
    stk[tt++] = u;
    dfs(u + 1);
    tt--;

}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}