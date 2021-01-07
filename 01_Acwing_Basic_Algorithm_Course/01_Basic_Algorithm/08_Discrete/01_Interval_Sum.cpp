//
// Created by Genes on 2020/12/9.
//
// 区间和

#include <algorithm>
#include <iostream>
#include <vector>

#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)

using namespace std;

typedef pair<int, int> pii;

const int N = 3e5 + 10;

int n, m;
int a[N], s[N];

vector<int> alls;  //存离散化之后的坐标
vector<pii> add, query;

int find(
    int x) {  // 在离散化后的数组中, 查找一个值为x的下标(第一个>=x), 并将其返回
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;  //为了方便前缀和, 下标从1开始
}

int main() {
    ios;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (int i = 0; i < add.size(); i++) {
        int x = find(add[i].first);
        a[x] += add[i].second;
    }

    //预处理前缀和
    for (int i = 1; i <= alls.size(); i++) {
        s[i] = s[i - 1] + a[i];
    }

    //处理询问
    for (int i = 0; i < query.size(); i++) {
        int l = find(query[i].first), r = find(query[i].second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
