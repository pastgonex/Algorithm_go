#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n;
struct Range
{
    int l, r;
    bool operator<(const Range& W) const
    {
        return l < W.l;
    }
} range[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }

    sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap;  // 将默认的大根堆转换为小根堆

    for (int i = 0; i < n; i++) {
        auto r = range[i];
        if (heap.empty() || heap.top() >= r.l) {
            heap.push(r.r);
        }
        else {
            heap.pop();
            heap.push(r.r);  // 将新的右端点加到堆中
        }
    }

    cout << heap.size() << endl;
    
    return 0;
}