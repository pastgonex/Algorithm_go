/*
 * Project: 02_AtCoder_Beginner_Contest 186
 * File Created:Monday, January 4th 2021, 5:21:56 pm
 * Author: Bug-Free
 * Problem:C - Unlucky 7
 */
#include <iostream>

using namespace std;

int n;

bool judge(int x, int progress) {
    while (x) {
        if (x % progress == 7) {
            return false;
        }
        x /= progress;
    }
    return true;
}

int main() {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (judge(i, 10) && judge(i, 8)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
