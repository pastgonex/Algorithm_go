/*
 * Project: Week03
 * File Created:Thursday, January 21st 2021, 10:29:04 am
 * Author: Bug-Free
 * Problem: AcWing 754. 平方矩阵 II 规律
 */
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int q[N][N];

int main() {
    int n;
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            q[i][i] = 1;  //正对角线
            for (int j = i + 1, k = 2; j < n; j++, k++) {
                q[i][j] = q[j][i] = k;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    cout << " ";
                }
                cout << q[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
