//
// Created by Genes on 2020/12/3.
//
// 最高的牛

#include <algorithm>
#include <iostream>
#include <set>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e4 + 10;

set<pair<int, int>> existed;
int n, p, h, m;
int c[N], d[N];

int main() {
    ios;
    cin >> n >> p >> h >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        if (!existed.count({a, b})) {
            existed.insert({a, b});
            d[a + 1]--, d[b]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + d[i];
        cout << h + c[i] << endl;
    }
    return 0;
}
