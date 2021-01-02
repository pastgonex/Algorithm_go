#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    //哨兵
    a.insert(a.begin(), 0);
    a.push_back(n + 1);

    vector<int> alls;

    int minx = n;
    for (int i = 0; i + 1 < a.size(); i++) {
        int cur = a[i + 1] - a[i] - 1;
        if (cur > 0) {
            alls.push_back(cur);
            minx = min(minx, cur);
        }
    }
    int res = 0;
    for (auto it : alls) {
        res += (it + minx - 1) / minx;
    }
    cout << res << endl;
    return 0;
}
