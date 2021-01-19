/*
 * Project: Week02
 * File Created:Friday, January 15th 2021, 1:41:35 pm
 * Author: Bug-Free
 * Problem:AcWing 1346. 回文平方
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

char get(int x) {
    // 把数字转换为字母
    if (x <= 9) {
        return x + '0';
    }
    return x - 10 + 'A';  // 10-> A  11->B...
}

string base(int n, int b) {
    string num;
    while (n) {
        num += get(n % b), n /= b;
    }
    reverse(num.begin(), num.end());
    return num;
}

bool check(string num) {
    for (int i = 0, j = num.size() - 1; i < j; i++, j--) {
        if (num[i] != num[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int b;
    cin >> b;
    for (int i = 1; i <= 300; i++) {
        auto num = base(i * i, b);
        if (check(num)) {
            cout << base(i, b) << " " << num << endl;
        }
    }
    return 0;
}
