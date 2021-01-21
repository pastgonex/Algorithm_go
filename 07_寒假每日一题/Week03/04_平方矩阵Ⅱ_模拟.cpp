/*
 * Project: Week03
 * File Created:Thursday, January 21st 2021, 11:12:27 am
 * Author: Bug-Free
 * Problem: AcWing 754. 平方矩阵 II 模拟
 */
#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            int k = 1;
            for (int j = i; j >= 1; j--,k++) {
                cout << j << " ";
            }
            for (int j = 2; k <= n; k++, j++) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
