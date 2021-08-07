/*
    思路：
        每次挑两个权值最小的点合并（所有的树中， 深度最深， 并且可以互为兄弟
*/

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> heap;
int n;

int main()
{
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        heap.push(x);
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