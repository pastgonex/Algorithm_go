/*
 * Project: 0x12_Queue
 * File Created:Saturday, December 26th 2020, 1:36:55 am
 * Author: Genesis
 */
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3 + 10, M = 1e6 + 10;

int team_id[M];

int n, C = 1;

int main() {
    while (cin >> n, n) {
        queue<int> Q[N];
        cout << "Scenario #" << C++ << endl;
        for (int i = 1; i <= n; i++) {
            int cnt;
            cin >> cnt;
            while (cnt--) {
                int x;
                cin >> x;
                team_id[x] = i;
            }
        }
        string op;
        while (cin >> op, op != "STOP") {
            if (op == "ENQUEUE") {
                int x;
                cin >> x;
                int tid = team_id[x];
                if (Q[tid].empty()) {
                    Q[0].push(tid);
                }
                Q[tid].push(x);
            } else {
                int tid = Q[0].front();
                auto& q = Q[tid];
                cout << q.front() << endl;
                q.pop();
                if (q.empty()) {
                    Q[0].pop();
                }
            }
        }
        cout << endl;
    }
    return 0;
}
