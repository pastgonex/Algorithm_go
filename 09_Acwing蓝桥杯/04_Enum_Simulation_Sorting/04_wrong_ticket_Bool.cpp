//
// Created by Genes on 2020/9/21.
//
// 错误票据
// 算法二: 开bool数组

#include<iostream>
#include<sstream>
#include<climits>

using namespace std;

const int N = 1e5 + 10;

int a[N];
int cnt;
bool st[N];

int main() {
    ios::sync_with_stdio(false);
    string line;
    cin >> cnt;
    getline(cin, line); //去除第一行的换行
    int k = 0;
    int minN = INT_MAX, maxN = INT_MIN;
    while (cnt--) {
        getline(cin, line);
        stringstream ssin(line);
        while (ssin >> a[k]) {
            if (minN > a[k]) minN = a[k];
            if (maxN < a[k]) maxN = a[k];
            k++;
        }
    }
    int n = 0, m = 0;
    for (int i = 0; i < k; i++) {
        if (!st[a[i]]) {
            st[a[i]] = true;
        } else {
            n = a[i];
        }
    }
    for (int i = minN + 1; i < maxN; i++) {
        if (!st[i]) {
            m = i;
            break;
        }
    }
    cout << m << " " << n << endl;
    return 0;
}
