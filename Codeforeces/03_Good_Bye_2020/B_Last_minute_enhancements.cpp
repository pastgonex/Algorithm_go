/*
 * Project: 03_Good_Bye_2020
 * File Created:Wednesday, December 30th 2020, 11:05:07 pm
 * Author: Bug-Free
 * Problem:B. Last minute enhancements
 */
// Greedy+set
#include <iostream>
#include <set>

using namespace std;

const int N = 1e5 + 10;
int n, t;

void solve() {
    set<int> alls;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (alls.count(x)) {
            x++;
        }
        alls.insert(x);
    }
    cout << alls.size() << endl;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
