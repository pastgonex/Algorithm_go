//
// Created by Genes on 2020/12/15.
//
// 邻值查找
#include<iostream>
#include<vector>
#include<algorithm>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int> PII;

int n;
int p[N], l[N], r[N];
PII a[N], ans[N];

int main() {
    ios;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n);

    a[0].first = -2e9 - 1, a[n + 1].first = 2e9 + 1;
    for (int i = 1; i <= n; i++) {
        l[i] = i - 1, r[i] = i + 1;
        p[a[i].second] = i; //每个点在双链表中的位置
    }

    for (int i = n; i >= 2; i--) {
        // 找到当前元素在双链表中的位置
        int j = p[i], left = l[j], right = r[j];
        int lv = abs(a[j].first - a[left].first), rv = abs(a[j].first - a[right].first);
        if (lv <= rv) {
            ans[i] = {lv, a[left].second};
        } else {
            ans[i] = {rv, a[right].second};
        }
        l[right] = left, r[left] = right;
    }
    for (int i = 2; i <= n; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}