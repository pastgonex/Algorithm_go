//
// Created by Genes on 2020/9/24.
//
// 移动距离
/*
1  2 3  4  5  6
12 11 10 9  8  7
13 14 15 16 17 18
 */

// 奇数行是正常的, 偶数行是反向的
// 每行的最后一个都是w的倍数 (%w==0) 或者 %w==1 可以通过当前的数字%w 来确定
//

#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, m, n;
    cin >> w >> m >> n;
    m--, n--;  //序号减1, 方便利用公式求行号和列号, 让编号从0开始计算

    // 定位 n 与 m 的行和列
    int x1 = m / w, x2 = n / w; //行号
    int y1 = m % w, y2 = n % w; //列号

    if (x1 & 1) y1 = w - 1 - y1; //特判, 是否为奇数行, 所有的奇数行, 都需要翻转坐标
    if (x2 & 1) y2 = w - 1 - y2; //如果是奇数行, 那么所有的列都要翻转一下
/*   0  1  2 3 4 5

 0   0  1  2 3 4 5
 1   11 10 9 8 7 6    1 --> 4   0 --> 5   总和都是不变的, 都是 w-1, 所以直接 w-1-y1  就翻转了
*/

    //曼哈顿距离
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    return 0;

}