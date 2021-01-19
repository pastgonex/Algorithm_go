/*
 * Project: Huffman树
 * File Created:Saturday, January 16th 2021, 5:34:08 pm
 * Author: Bug-Free
 * Problem:Acwing 149. 荷马史诗
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;

const int N = 1e5 + 10;

int n, m;
priority_queue<PLI, vector<PLI>, greater<PLI>> heap;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        LL w;
        cin >> w;
        heap.push({w, 0});
    }

    while ((n - 1) % (m - 1)) {
        heap.push({0ll, 0});
        n++;
    }

    LL res = 0;
    while (heap.size() > 1) {
        LL sum = 0;
        int depth = 0;
        for (int i = 0; i < m; i++) {
            sum += heap.top().first;
            depth = max(depth, heap.top().second);
            heap.pop();
        }
        res += sum;
        heap.push({sum, depth + 1});
    }

    cout << res << endl;
    cout << heap.top().second << endl;
    return 0;
}
