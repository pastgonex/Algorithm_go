/*
 * Project: 07_KMP
 * File Created:Monday, January 4th 2021, 9:12:14 am
 * Author: Bug-Free
 * Problem: AcWing 831. KMP字符串
 */

// brute-force 暴力

// #include <iostream>

// using namespace std;

// const int N = 1e5 + 10, M = 1e6 + 10;

// int n, m;
// char S[M], P[N];

// int main() {
//     cin >> m >> (P + 1) >> n >> (S + 1);
//     for (int i = 1; i <= n - m + 1; i++) {
//         bool flag = true;
//         for (int j = 1; j <= m; j++) {
//             if (S[i + j - 1] != P[j]) {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag) {
//             cout << i - 1 << " ";  //题目中下标从0开始
//         }
//     }
//     return 0;
// }
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
int ne[N];
char s[M], p[N];

void get_next() {
    ne[1] = 0;  //我们的下标从1开始, 题目中的下标从0开始
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) {  //只要j不为0(退无可退)且 p[i]!=p[j+1];
            j = ne[j];
        }
        if (p[i] == p[j + 1]) {
            j++;
        }
        ne[i] = j;  // ne[i] 表示 "p中以i结尾的非前缀子串" 与
                    // "A的前缀＂能够匹配的最大长度->
                    // 即： ne[i] = max{j}, 其中j<i 并且 A[i-j+1 ~ i]=A[1~j]
    }
}

int main() {
    cin >> n >> (p + 1) >> m >> (s + 1);

    //求next数组
    get_next();

    // KMP匹配过程
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) {
            j = ne[j];
        }
        if (s[i] == p[j + 1]) {
            j++;
        }
        if (j == n) {
            cout << i - n << " ";
            j = ne[j];
        }
    }
    return 0;
}
