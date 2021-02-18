/*
 * File: 03_数独2.cpp
 * Project: 0x23_剪枝
 * File Created: Sunday, 14th February 2021 3:12:45 am
 * Author: Bug-Free
 * Problem: AcWing 169. 数独2
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 16;

// map[N] 表示 log_2 ^ N ,  ones[N] 表示N这个数字的二进制表示中， 有多少个1
int  map[1 << N], ones[1 << N];
int  state[N][N];    // 存每个格子的状态
char str[N][N + 1];  // 存整个16*16的数独

// bakcup 备份
int  bstate[N * N + 1][N][N], bstate2[N * N + 1][N][N];
char bstr[N * N + 1][N][N + 1];

inline int lowbit(int x)
{
    return x & -x;
}

void draw(int x, int y, int c)
{
    str[x][y] = 'A' + c;

    for (int i = 0; i < N; i++) {
        state[x][i] &= ~(1 << c);  //当前这一行都不能填传入的c这个字母了
        state[i][y] &= ~(1 << c);  // 当前这一列也都不能填传入的c这个字母了
    }

    // 当前这个 16宫格也都不能填传入的c这个字母了
    int sx = x / 4 * 4, sy = y / 4 * 4;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            // 只把这一位的状态变成0， 标记为这个字母不能填了
            state[sx + i][sy + j] &= ~(1 << c);

    //在二进制中填好了， 就只有一种备选方案了 =  1 << c
    state[x][y] = 1 << c;
}

bool dfs(int cnt)
{
    if (!cnt)
        return true;

    int kcnt = cnt;
    // 记录一下第 kcnt层的状态  bstate是一个三维数组
    memcpy(bstate[kcnt], state, sizeof state);
    memcpy(bstr[kcnt], str, sizeof str);  // 记录一下 kcnt层的数独

    // 每个空格，如果不能填则返回false；如果只有一个选项，则直接填上
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (str[i][j] == '-') {
                if (!state[i][j]) {
                    // 恢复现场
                    memcpy(state, bstate[kcnt], sizeof state);
                    memcpy(str, bstr[kcnt], sizeof str);
                    return false;
                }
                // 直接填上
                if (ones[state[i][j]] == 1) {
                    draw(i, j, map[state[i][j]]);
                    cnt--;
                }
            }
        }
    }

    // 每一行，如果某个字母不能填，则返回false；如果某个字母只有一种填法，则直接填
    for (int i = 0; i < N; i++) {
        // sor存储所有状态or（或）的结果， sand存储所有数字&的结果
        int sor = 0, sand = (1 << N) - 1;  //把所有位先置成1
        int drawn = 0;                     // 当前这一行已经填上了哪些字母， 用drawn表示
        for (int j = 0; j < N; j++) {
            int s = state[i][j];
            sand &= ~(sor & s);  // 把可以填多个地方的【字母】去掉
            sor |= s;            // 所有状态的并集

            if (str[i][j] != '-')      // 如果这个格子已经有字母了
                drawn |= state[i][j];  //则把这个【字母】标记为1
        }

        if (sor !=
            (1 << N) - 1) {  //如果所有状态的并集，不是16个1的话，就恢复现场
            memcpy(state, bstate[kcnt], sizeof state);
            memcpy(str, bstr[kcnt], sizeof str);
            return false;
        }

        // sand中所有是1的位，表示只能填在某个位置上
        for (int j = sand; j; j -= lowbit(j)) {
            int t = lowbit(j);   // 枚举每一个1
            if (!(drawn & t)) {  //如果这个位置之前没有填过的话
                for (int k = 0; k < N; k++)
                    if (state[i][k] & t) {  // 看一下在哪个位置
                        draw(i, k, map[t]);
                        cnt--;
                        break;
                    }
            }
        }
    }

    // 每一列，如果某个字母不能填，则返回false；如果某个字母只有一种填法，则直接填
    for (int i = 0; i < N; i++) {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        for (int j = 0; j < N; j++) {
            int s = state[j][i];
            sand &= ~(sor & s);
            sor |= s;

            if (str[j][i] != '-')
                drawn |= state[j][i];
        }

        if (sor != (1 << N) - 1) {
            memcpy(state, bstate[kcnt], sizeof state);
            memcpy(str, bstr[kcnt], sizeof str);
            return false;
        }

        for (int j = sand; j; j -= lowbit(j)) {
            int t = lowbit(j);
            if (!(drawn & t)) {
                for (int k = 0; k < N; k++)
                    if (state[k][i] & t) {
                        draw(k, i, map[t]);
                        cnt--;
                        break;
                    }
            }
        }
    }

    // 每个16宫格，如果某个字母不能填，则返回false；如果某个字母只有一种填法，则直接填
    for (int i = 0; i < N; i++) {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        for (int j = 0; j < N; j++) {
            int sx = i / 4 * 4, sy = i % 4 * 4;
            int dx = j / 4, dy = j % 4;
            int s = state[sx + dx][sy + dy];
            sand &= ~(sor & s);
            sor |= s;

            if (str[sx + dx][sy + dy] != '-')
                drawn |= state[sx + dx][sy + dy];
        }

        if (sor != (1 << N) - 1) {
            memcpy(state, bstate[kcnt], sizeof state);
            memcpy(str, bstr[kcnt], sizeof str);
            return false;
        }
        for (int j = sand; j; j -= lowbit(j)) {
            int t = lowbit(j);
            if (!(drawn & t)) {
                for (int k = 0; k < N; k++) {
                    int sx = i / 4 * 4, sy = i % 4 * 4;
                    int dx = k / 4, dy = k % 4;
                    if (state[sx + dx][sy + dy] & t) {
                        draw(sx + dx, sy + dy, map[t]);
                        cnt--;
                        break;
                    }
                }
            }
        }
    }

    if (!cnt)
        return true;

    // 选择被选方案最少的格子
    int x, y, s = 100;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (str[i][j] == '-' && ones[state[i][j]] < s) {
                s = ones[state[i][j]];
                x = i, y = j;
            }
        }
    }
    memcpy(bstate2[kcnt], state, sizeof state);
    for (int i = state[x][y]; i; i -= lowbit(i)) {
        memcpy(state, bstate2[kcnt], sizeof state);
        draw(x, y, map[lowbit(i)]);
        if (dfs(cnt - 1)) {
            return true;
        }
    }

    memcpy(state, bstate[kcnt], sizeof state);
    memcpy(str, bstr[kcnt], sizeof str);
    return false;
}

int main()
{
    for (int i = 0; i < N; i++)
        map[1 << i] = i;
    for (int i = 0; i < 1 << N; i++) {
        for (int j = i; j; j -= lowbit(j))
            ones[i]++;
    }

    while (cin >> str[0]) {
        for (int i = 1; i < N; i++)
            cin >> str[i];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                state[i][j] = (1 << N) - 1;

        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (str[i][j] != '-')
                    draw(i, j, str[i][j] - 'A');
                else
                    cnt++;

        dfs(cnt);

        for (int i = 0; i < N; i++)
            cout << str[i] << endl;
        cout << endl;
    }

    return 0;
}