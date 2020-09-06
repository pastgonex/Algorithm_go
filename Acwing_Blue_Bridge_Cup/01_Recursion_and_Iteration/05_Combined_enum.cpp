//! 保持升序, 是一个局部的属性, 只要保证每次新加的数大于前一个数
//! a1<a2 a2<a3
//! 从前往后, 依次枚举每个位置是 多少
//! 核心想一下dfs是哪些参数
//! 三个位置 way[]
//! 当前该枚举哪个位置 start    中间位置就是 strat从前一个位置 +1
//! 当前最小可以从哪里枚举
//! 无非 选或不选  或者组合类型枚举(参数多一些,但是数组少了一个)  排列型枚举需要一个判重枚举
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> chosen;

void dfs(int u, int start) {
    if (u + n - start < m)
        return;
    if (u > m) {
        for (int i = 0; i < m; i++) {
            if (i > 0)
                printf(" ");
            printf("%d", chosen[i]);
        }
        puts("");
        return;
    }
    for (int i = start; i <= n; i++) {
        chosen.push_back(i);
        dfs(u + 1, i + 1);
        chosen.pop_back();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    dfs(1, 1);
    return 0;
}
