/*
 * Project: 03_Good Bye 2020
 * File Created:Wednesday, December 30th 2020, 10:36:41 pm
 * Author: Bug-Free
 * Problem: A. Bovine Dilemma
 */
// Brute-force+set
#include <iostream>
#include <set>

using namespace std;

const int N = 5e1 + 5;

int t, n;
int a[N];
set<int> alls;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int cur = a[j] - a[i];
                alls.insert(cur);
            }
        }
        cout << alls.size() << endl;
        alls.clear();
    }
    return 0;
}
