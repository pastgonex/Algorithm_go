// 分情况讨论，考虑m的奇偶性
#include <iostream>

using namespace std;

int n, m;

bool odd(int n)
{
    return n % 2 != 0;
}

int main()
{
    cin >> n >> m;

    int res = 0;

    res += n * (m / 2);

    if (odd(m)) {
        res += n / 2;
    }

    cout << res << endl;

    return 0;
}