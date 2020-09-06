//
// Created by Genes on 2020/8/31.
//

#include <iostream>

using namespace std;

int p, q;

bool dfs(int m) //判断是否凑不出来  凑不出来 false;
{
    if (!m) return true; // 如果m==0, 就说明凑出来了
    if (m >= p && dfs(m - p)) return true; // 第一个分支
    if (m >= q && dfs(m - q)) return true; // 第二个分支
    return false;
}

int main() {
    cin >> p >> q;
    int res = 0;
    for (int i = 1; i <= 1000; i++) {
        if (!dfs(i)) res = i;
    }
    cout << res << endl;
    return 0;
}
