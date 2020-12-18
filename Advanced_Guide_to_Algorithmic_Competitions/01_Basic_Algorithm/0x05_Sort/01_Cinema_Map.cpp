#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define pii pair<int,int>

const int N = 2e5 + 10;

int n, m, sc[N], lan;
unordered_map<int, int> p, q;

pii mv[N], mv_ans[N];

int cmp(pii a, pii b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sc[i];
        if (p[sc[i]] == 0) {
            p[sc[i]] = (++lan);
            sc[i] = lan;
        } else {
            sc[i] = p[sc[i]];
        }
        q[sc[i]]++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> mv[i].first;
        mv[i].first = q[p[mv[i].first]];
    }
    for (int i = 1; i <= m; i++) {
        cin >> mv[i].second;
        mv[i].second = q[p[mv[i].second]];
        mv_ans[i] = mv[i];
    }
    sort(mv + 1, mv + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        if (mv_ans[i] == mv[1]) {
            cout << i;
            break;
        }
    }
    return 0;
}