/*
 * Project: Week3
 * File Created:Tuesday, January 19th 2021, 6:26:45 pm
 * Author: Bug-Free
 * Problem:AcWing 1532. 找硬币 双指针
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0, j = n - 1; i < j; i++) {
        while (i < j && a[i] + a[j] > m) {
            j--;
        }
        if (i < j && a[i] + a[j] == m) {
            cout << a[i] << " " << a[j] << endl;
            return 0;
        }
    }

    cout << "No Solution" << endl;
    return 0;
}
