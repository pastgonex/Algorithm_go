/*
 * Project: Huffman树
 * File Created:Saturday, January 16th 2021, 12:58:15 pm
 * Author: Bug-Free
 * Problem:AcWing 148. 合并果子
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e4 + 10;

int n;
priority_queue<int, vector<int>, greater<int>> heap;  //小根堆

int main() {
    cin >> n;
    while (n--) {
        int v;
        cin >> v;
        heap.push(v);
    }
    int ans = 0;
    while (heap.size() > 1) {
        auto a = heap.top();
        heap.pop();
        auto b = heap.top();
        heap.pop();
        ans += a + b;
        heap.push(a + b);
    }
    cout << ans << endl;
    return 0;
}
