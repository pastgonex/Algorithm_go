/*
 * Project: Week3
 * File Created:Monday, January 18th 2021, 9:37:22 am
 * Author: Bug-Free
 * Problem:AcWing 1208. 翻硬币
 */
#include <iostream>

using namespace std;

string start, aim;

void turn(int x) {
    if (start[x] == '*') {
        start[x] = 'o';
    } else {
        start[x] = '*';
    }
}

int main() {
    cin >> start >> aim;
    int n = start.size();

    int res = 0;

    for (int i = 0; i < n - 1; i++) {
        if (start[i] != aim[i]) {
            turn(i + 1);
            res++;
        }
    }

    cout << res << endl;
    return 0;
}
