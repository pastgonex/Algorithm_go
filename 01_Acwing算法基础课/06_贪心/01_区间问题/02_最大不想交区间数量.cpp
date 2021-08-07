#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

#define x first
#define y second

int n;
vector<pii> interval;

bool cmp(pii a, pii b)
{
    return a.y < b.y;
}

int main()
{
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        interval.push_back({l, r});
    }

    sort(interval.begin(), interval.end(), cmp);

    int ans = 0, ed = -1e9 - 10;
    for (auto item : interval) {
        if (ed < item.x) {
            ans++;
            ed = item.y;
        }
    }

    cout << ans << endl;

    return 0;
}