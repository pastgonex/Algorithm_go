#include<iostream>
#include <algorithm>
#include<vector>
#include<cstring>

#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int> pii;

int n, d, k;
bool st[N];
pii logs[N];
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++) {
        cin >> logs[i].x >> logs[i].y;
    }
    sort(logs, logs + n);
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int t = logs[i].x;
        for (int j = i + 1; j < n; j++) {
            if (logs[j].x - t < d && logs[j].y == logs[i].y) {
                cnt++;
            }
        }
        if (cnt >= k) {
            st[logs[i].y] = true;
        }
    }

    for (int i = 0; i <= 1e5 + 10; i++) {
        if (st[i]) {
            cout << i << endl;
        }
    }
    return 0;
}