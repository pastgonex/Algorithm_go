#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int n;
bool st[N];

void init()
{
    for (int i = 1000; i < 9999; i++) {
        int t = i;
        int a = t / 1000, b = t / 100 % 10, c = t / 10 % 10, d = t % 10;
        if (a != b && a != c && a != d && b != c && b != d && c != d) {
            st[i] = true;
        }
    }
}

int main()
{
    cin >> n;
    init();
    for (int i = n + 1; i <= 9999; i++) {
        if (st[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}