/*
 * Project: 0x17_二叉堆
 * File Created:Thursday, January 14th 2021, 12:02:45 pm
 * Author: Bug-Free
 * Problem:AcWing 146. 序列
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 2e3 + 10;

int n, m;
// a和b是每次需要合并的序列, c是中间临时缓存的序列
int a[N], b[N], c[N];

void work() {
    // 默认是大根堆, 这样可以变成小根堆
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for (int i = 0; i < n; i++) {     // 小根堆, 堆顶就是最小值
        heap.push({a[0] + b[i], 0});  // push进去的是一个pair
    }
    for (int i = 0; i < n; i++) {
        auto t = heap.top();
        heap.pop();
        int s = t.first, p = t.second;
        c[i] = s;
        heap.push({s - a[p] + a[p + 1], p + 1});
    }
    // memcpy最后一个参数是字节, 一个int包含4个字节
    memcpy(a, c, 4 * n);  //拷贝数组
    // for (int i = 0; i < n; i++) {
    //     a[i] = c[i];
    // }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];  //先读入一行
        }
        sort(a, a + n);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b[j];
            }
            // sort(b, b + n);
            work();  //每次合并两组, 共合并m-1次
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
