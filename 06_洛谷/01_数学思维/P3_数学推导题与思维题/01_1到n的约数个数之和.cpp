/*
 * Project: 03_Mathematics_thinking
 * File Created:Wednesday, January 6th 2021, 7:13:05 pm
 * Author: Bug-Free
 * Problem: 1到n的约数个数之和
 */

#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += n / i;
    }
    cout << sum << endl;
    return 0;
}
