/*
 * Project: 02_AtCoder_Beginner_Contest 186
 * File Created:Monday, January 4th 2021, 5:12:15 pm
 * Author: Bug-Free
 * Problem:A - Brick
 */

// 给定 最大容量N 和 每一块砖头的重量w
// 问最多可以装多少块砖头 -> 下取整

#include <iostream>

using namespace std;

int n, w;
int main() {
    cin >> n >> w;
    cout << n / w << endl;
    return 0;
}
