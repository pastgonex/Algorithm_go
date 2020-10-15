//
// Created by Genes on 2020/10/11.
//

// 递增序列
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int x;
    while (true) {
        cin >> x;

        if (!x) break;

        for (int i = 1; i <= x; i++) cout << i << ' ';
        cout << endl;
    }

    return 0;
}