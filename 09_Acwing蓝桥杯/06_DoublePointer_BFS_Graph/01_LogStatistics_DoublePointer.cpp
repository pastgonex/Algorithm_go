// 双指针做法

#include<iostream>
#include<algorithm>

using namespace std;

#define x first
#define y second

const int N = 1e5 + 10;

typedef pair<int, int> pii;

int n, d, k;
bool st[N];
int cnt[N];
pii logs[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++) {
        cin >> logs[i].x >> logs[i].y;
    }
    sort(logs, logs + n);
    for (int i = 0, j = 0; i < n; i++) {
        int id = logs[i].y;
        cnt[id]++;
        while (logs[i].x - logs[j].x >= d) {
            cnt[logs[j].y]--;
            j++;
        }
        if (cnt[id] >= k) {
            st[id] = true;
        }
    }
    for (int i = 0; i <= 1e5; i++) {
        if (st[i]) {
            cout << i << endl;
        }
    }
    return 0;
}
