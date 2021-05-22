/*
    思路：
        直接记录每个数字的下标即可
        维护两端 l，r
*/
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2 * 1e5;

int q;
int idx[N];

int main()
{
    cin >> q;
    string op;
    int x;
    int l = 0, r = -1;
    while (q--) {
        cin >> op >> x;
        if (op == "L") {
            idx[x] = --l;
        }
        else if (op == "R") {
            idx[x] = ++r;
        }
        else {
            cout << min(r - idx[x], idx[x] - l) << endl;
        }
    }

    return 0;
}