//
// Created by Genes on 2020/12/19.
//
#include<iostream>

using namespace std;

const int N = 1e3 + 10;

int t;
int n;
string a, b;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        int r_win_b = 0, b_win_r = 0;
        for (int i = 0; i < n; i++) {
            r_win_b += a[i] > b[i], b_win_r += b[i] > a[i];
        }
        if (r_win_b == b_win_r) {
            cout << "EQUAL" << endl;
        } else if (r_win_b > b_win_r) {
            cout << "RED" << endl;
        } else {
            cout << "BLUE" << endl;
        }
    }
    return 0;
}
