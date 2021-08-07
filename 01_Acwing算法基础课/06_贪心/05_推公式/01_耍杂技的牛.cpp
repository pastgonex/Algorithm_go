/*
    思路；
        对于任意一个叠罗汉的方案， 如果存在两头相邻的牛， W_i+1 + s_i+1 < w_i + s_i
        就可以将这两头牛交换， 可以证明出， 将两头牛交换之后， 最大值不会变大
        那么就必然可以变成所有牛 从小到大排序的 顺序
 */

#include <algorithm>
#include <iostream>

#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;

const int N = 5e4 + 10;

int n;
pii a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, s;
        cin >> w >> s;
        a[i] = {w + s, w};
    }

    sort(a, a + n);
    int res = -1e9;
    for (int i = 0, sum = 0; i < n; i++) {
        int w = a[i].y, s = a[i].x - w;
        res = max(res, sum - s);
        sum += w;
    }

    cout << res << endl;
    return 0;
}