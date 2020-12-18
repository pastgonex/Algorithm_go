//
// Created by Genes on 2020/12/11.
//
// 区间合并

#include<iostream>
#include<vector>
#include<algorithm>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> seg;

int main() {
    ios;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        seg.push_back({l, r});
    }
    sort(seg.begin(), seg.end());
    int ans = 1;
    int end = seg[0].second;
    for (int i = 1; i < seg.size(); i++) {
        if (seg[i].first > end) {
            end = seg[i].second;
            ans++;
        } else if (seg[i].second > end) {
            end = seg[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}