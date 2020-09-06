// 顺序任意
// 每一个位置至多只按一次
// 只要第一行的位置确定, 那么第二行的操作就被唯一确定了(第一行暗的格子的下面)
// 每一行开关的操作, 都被上一行开关的亮灭状态所唯一确定
// 最后, 最后一行特判一下, 如果发现没有全亮-> 就说明这个方案无解
// 先宏观考虑, 再敲定细节
// 特殊技巧: i>>k&1 看一下第 k 位二进制数字是不是 1
// ------------------> y
// |
// |
// |
// |
// |
// x
// 枚举一下偏移量 上(-1,0)  下(1,0) 左(0,-1) 右 (0,1) 中间(0,0)
// turn(x,y)
// 时间复杂度 32*25*5*500 == 2e6 < 1e9
// 如果是 8 个偏移量---> 写一个两重循环 i 从 -1枚举到1   j从-1枚举到1  中间特判一下 0,0

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 6; //因为是字符, 最后一位是 '/0',因此多开一位

char g[N][N], backup[N][N];
int dx[5] = {-1, 1, 0, 0, 0};
int dy[5] = {0, 0, -1, 1, 0};

void turn(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;
        g[a][b] ^= 1; // '0'是48 所以 ^1就是49 =='1'
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 5; i++) scanf("%s", g[i]);
        int res = 10;
        for (int op = 0; op < 32; op++) {
            memcpy(backup, g, sizeof g);
            int step = 0;
            for (int i = 0; i < 5; i++)
                if (op >> i & 1) {
                    step++;
                    turn(0, i);
                }

            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 5; j++)
                    if (g[i][j] == '0') {
                        step++;
                        turn(i + 1, j);
                    }

            bool dark = false;
            for (int i = 0; i < 5; i++)
                if (g[4][i] == '0') {
                    dark = true;
                    break;
                }

            if (!dark) res = min(res, step);
            memcpy(g, backup, sizeof g);
        }

        if (res > 6) res = -1;

        printf("%d\n", res);
    }

    return 0;
}