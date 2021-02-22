/*
 * Project: Week02
 * File Created:Saturday, January 16th 2021, 10:37:15 am
 * Author: Bug-Free
 * Problem:AcWing 422. 校门外的树
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e2 + 10;

typedef pair<int, int> PII;

int n, m;
vector<PII> alls;
vector<PII> ans;

void merge()
{
    int st = alls[0].first, ed = alls[0].second;
    for (int i = 1; i < alls.size(); i++) {
        if (ed < alls[i].first) {
            ans.push_back({st, ed});
            st = alls[i].first, ed = alls[i].second;
        }
        else {
            ed = max(ed, alls[i].second);
        }
    }
    if (ed != alls[0].second) {
        ans.push_back({st, ed});
    }
}

int main()
{
    cin >> n >> m;
    n++;  // 一共有 n+1 棵树
    while (m--) {
        int l, r;
        cin >> l >> r;
        alls.push_back({l, r});
    }

    sort(alls.begin(), alls.end());

    merge();

    int res = 0;
    for (auto it : ans) {
        // cout << it.first << " " << it.second << endl;
        res += it.second - it.first + 1;
    }
    cout << n - res << endl;
    return 0;
}
