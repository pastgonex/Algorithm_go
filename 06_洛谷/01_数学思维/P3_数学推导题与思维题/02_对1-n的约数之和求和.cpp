/*
 * Project: 03_Mathematics_thinking
 * File Created:Wednesday, January 6th 2021, 7:43:06 pm
 * Author: Bug-Free
 * Problem: 02_ 对1-n的约数之和求和
 */

#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += n / i * i;  //考虑每个数对答案的贡献
    }
    cout << sum << endl;
    return 0;
}
