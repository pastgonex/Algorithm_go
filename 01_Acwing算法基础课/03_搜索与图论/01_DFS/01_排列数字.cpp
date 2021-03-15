/*
 * Project: DFS
 * File Created:Wednesday, January 20th 2021, 4:34:50 pm
 * Author: Bug-Free
 * Problem: AcWing 842. 排列数字
 */
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

vector<int> chosen;
bool st[N];
int n;

void dfs(int u) {
    if (u == n + 1) {  //问题边界
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << chosen[i];
        }
        puts("");
    }
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            st[i] = true;
            chosen.push_back(i);
            dfs(u + 1);
            chosen.pop_back();
            st[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);  //主函数中的调用入口
    return 0;
}
