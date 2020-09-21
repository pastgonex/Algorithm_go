//
// Created by Genes on 2020/9/15.
//
// 错误票据
// 算法一: 排序+判断

#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int a[N];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    string line;
    cin >> cnt;
    getline(cin, line); //忽略第一行空格
    int k = 0;
    while (cnt--) {
        getline(cin, line);
        stringstream ssin(line);
        while (ssin >> a[k]) k++;
    }
    sort(a, a + k);
    int n = 0, m = 0;
    for (int i = 1; i < k; i++) {
        if (a[i] == a[i - 1]) {
            n = a[i];
        } else if (a[i] >= a[i - 1] + 2) {
            m = a[i] - 1;
        }
    }
    cout << m << " " << n << endl;
    return 0;
}

