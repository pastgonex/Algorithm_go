//
// Created by Genes on 2020/8/30.
//
#include <iostream>

using namespace std;

const int N = 1e1 + 5;

int n;
int order[N];    //! 按顺序一次记录被选择的整数
bool chosen[N];  //! 标记被选择的整数

void dfs(int u) {
    if (u == n + 1) {  //! 边界
        for (int i = 1; i <= n; i++) {
            if (i > 1)
                printf(" ");
            printf("%d", order[i]);
        }
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!chosen[i]) {
            order[u] = i;  //! 让第 u 个位置的数等于 i
            chosen[i] = true;  //! 标记一下这个数已经被放置(使用)过了
            dfs(u + 1);        // todo 进入下一层
            order[u] = 0;  //! 恢复现场 这一行可以省略 因为下次进去会被覆盖
            chosen[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);  // todo 主函数中的调用入口
    return 0;
}
