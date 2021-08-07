#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;
vector<pii> interval;

bool cmp(pii a, pii b)
{
    return a.second < b.second;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        interval.push_back({l, r});
    }

    // 按区间右端点排序
    sort(interval.begin(), interval.end(), cmp);

    int ed = -1e9 - 10, cnt = 0;

    for (auto item : interval) {
        if (ed < item.x) {
            ed = item.y;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}