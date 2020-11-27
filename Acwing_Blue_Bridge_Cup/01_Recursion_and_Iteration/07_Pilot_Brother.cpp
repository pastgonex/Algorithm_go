// 目标的把所有的符号变成 '-' 号
// 4*4=16  O(2^16) O(65536)
// 因此可以暴力枚举所有方案
// dfs
// 如果方案数相同, 最后输出的时候优先按照 横坐标排序, 然后纵坐标(从左到右, 从上到下)
// 1. 枚举所有方案(二进制方式) 从 0 枚举到 2^16-1
// 每一个数都是16位的二进制数
// 2. 按照这个方案, 我操作一下状态
// 3. 判断一下是否全部打开, 如果全部打开就记录一下方案
// 时间复杂度 (2^16)*(16*7+16+16) 大概是 10,000,000 的时间复杂度
// 解释: 2^16种方案数
//      16个格子
//      每个开关最多操作7个格子(中间的开关)
//      +16 每个格子判断一下开不开
//         +16 如果全打开, 那就记录一下方案(最坏是每个格子都操作了一次, 所以是16)
// 将二维变成一维进行标号
// 但是我们是用二进制进行枚举(0-2^16-1) 当包含的1的个数相同的时候, 必然是优先枚举1更靠前的方案
// 也就是 十进制越大的
// 字典序最小, 步数最小的题型(猜测答案是唯一的)
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

#define x first
#define y second // 好处是 .first .second 的时候, 可以.x .y (=-=)

using namespace std;

typedef pair<int, int> PII;

const int N = 5;

char g[N][N], backup[N][N];

int get(int x, int y) {
    return x * 4 + y;
}

void turn_one(int x, int y) {
    if (g[x][y] == '-')
        g[x][y] = '+';
    else
        g[x][y] = '-';
}

void turn_all(int x, int y) {
    for (int i = 0; i < 4; i++) {
        turn_one(x, i);
        turn_one(i, y);
    }
    turn_one(x, y);
}

int main() {
    for (int i = 0; i < 4; i++)
        scanf("%s", g[i]);
    vector<PII> ans;
    for (int op = 0; op < (1 << 16); op++) // 1<<16 就是2^16
    {
        vector<PII> location;
        memcpy(backup, g, sizeof backup); //备份
        //进行操作
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                if (op >> get(i, j) & 1) {
                    location.emplace_back(i, j);
                    turn_all(i, j);
                }
            }
        // 判断所有开关是不是都打开了
        bool have_close = false;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                if (g[i][j] == '+') {
                    have_close = true;
                    break;
                }
            }

        if (!have_close) {
            if (ans.empty() || ans.size() > location.size())
                ans = location; //! 记录操作数少的
        }
        memcpy(g, backup, sizeof g); // 还原
    }
    printf("%d\n", ans.size());
    for (auto op : ans) {
        printf("%d %d\n", op.x + 1, op.y + 1); //输出的下标是从1开始的, 所以要+1
    }
    return 0;
}
