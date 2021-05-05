#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n, p, q;
bool st[N];

int main()
{
    cin >> n;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        st[x] = true;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        st[x] = true;
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        puts("I become the guy.");
    }
    else {
        puts("Oh, my keyboard!");
    }
    return 0;
}
