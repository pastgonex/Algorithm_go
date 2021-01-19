/*
 * Project: 10_堆
 * File Created:Wednesday, January 13th 2021, 10:03:02 pm
 * Author: Bug-Free
 * Problem:AcWing 838. 堆排序
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int h[N], cnt;

void down(int u) {
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) {
        t = u * 2;
    }
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) {
        t = u * 2 + 1;
    }
    if (u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    cnt = n;
    for (int i = n / 2; i; i--) {
        down(i);
    }
    while (m--) {
        cout << h[1] << " ";  //输出堆顶（最小值）
        h[1] = h[cnt--];  //删除堆顶（用最后一个数覆盖第一个数） 并且长度 减1
        down(1);  //让覆盖好的数往下面走
    }
    cout << endl;
    return 0;
}
