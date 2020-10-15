//
// Created by Genes on 2020/10/11.
//
// 二进制中1的个数

#include<iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    int res = 0;
    unsigned int un = n;
    while (un) {
        res += un & 1, un >>= 1;
    }
    cout << res << endl;
    return 0;
}
