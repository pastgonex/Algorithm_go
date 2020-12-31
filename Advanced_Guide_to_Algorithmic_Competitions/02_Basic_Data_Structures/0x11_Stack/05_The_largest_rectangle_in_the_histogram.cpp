/*
 * Project: 0x11_Stack
 * File Created:Tuesday, December 29th 2020, 4:31:53 pm
 * Author: Bug-Free
 * Problem:AcWing 131. 直方图中最大的矩形
 */
// Brute-force
// #include <iostream>

// using namespace std;

// const int N = 1e5 + 10;

// int n;
// int res;
// int a[N];

// int main() {
//     while (cin >> n, n) {
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
//         for (int i = 0; i < n; i++) {
//             int cnt1 = 0, cnt2 = 0;
//             int j = i - 1;
//             while (j >= 0 && a[i] <= a[j]) {
//                 j--;
//                 cnt1++;
//             }
//             j = i + 1;
//             while (a[j] >= a[i] && j < n) {
//                 j++;
//                 cnt2++;
//             }
//             res = max(res, (cnt1 + cnt2 + 1) * a[i]);
//         }
//         cout << res << endl;
//     }
//     return 0;
// }

