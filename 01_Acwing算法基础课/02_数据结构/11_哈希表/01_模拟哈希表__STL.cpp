/*
 * Project: 11_哈希表
 * File Created:Sunday, January 17th 2021, 1:15:20 pm
 * Author: Bug-Free
 * Problem:AcWing 840. 模拟散列表
 */
#include <iostream>
#include <set>

using namespace std;

set<int> m;

int n;

int main() {
    cin >> n;
    string op;
    int x;
    while (n--) {
        cin >> op >> x;
        if (op == "I") {
            m.insert(x);
        } else {
            if (m.count(x)) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    return 0;
}
