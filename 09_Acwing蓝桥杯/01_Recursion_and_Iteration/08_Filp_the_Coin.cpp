// 定一个初始状态, 可以进行一些操作, 最小多少次操作可以达到目标状态 最常用(bfs)(复杂度高)
// 可以把两个相邻的硬币之间有一个开关 最多有 99个
// 每次可以想一下能变这个硬币的开关有哪些
// 经过模拟发现, 他其实是一个递推的问题

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n;
char start[N], aim[N];

void turn(int x) {
    switch (start[x]) {
        case '*':
            start[x] = 'o';
            break;
        case 'o':
            start[x] = '*';
            break;
    }
}

int main() {
    cin >> start >> aim;
    int res = 0;
    n = strlen(start);
    for (int i = 0; i < n - 1; i++) {
        if (start[i] != aim[i]) {
            turn(i + 1); //这里本身不用管, 只要变一下i+1就好
            res++;
        }
    }
    printf("%d\n", res);
    return 0;
}
