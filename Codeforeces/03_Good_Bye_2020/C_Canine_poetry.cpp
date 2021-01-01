/*
 * Project: 03_Good_Bye_2020
 * File Created:Thursday, December 31st 2020, 10:50:33 am
 * Author: Bug-Free
 * Problem:C. Canine poetry
 */
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

string s;
int t;
bool used[N];

void solve() {
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
        bool use_need = false;
        if (s[i] == s[i - 1] && !used[i - 1]) {
            use_need = true;
        }
        if (i > 1 && s[i] == s[i - 2] && !used[i - 2]) {
            use_need = true;
        }
        used[i] = use_need;
        ans += used[i];
    }
    cout << ans << endl;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 
