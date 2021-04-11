#include <iostream>

using namespace std;

int n;

int exgcd(int a, int b, int& x, int& y)
{
    // return b ? exgcd(b, a % b, x, y) : a;
    // b为0的分支
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    // b不为0的分支
    int d = exgcd(b, a % b, y, x);  // 翻转x，y为了方便计算，递归到最后， 一定会得到 by+(a%b)x = d;
    // ax + b(y-(a/b)*x) = d
    // 因此x不变， y变为 y - (a / b) * x
    y -= (a / b) * x;
    return d;
}

int main()
{
    cin >> n;
    while (n--) {
        int a, b, x, y;
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << " " << y << " " << endl;
    }
    return 0;
}