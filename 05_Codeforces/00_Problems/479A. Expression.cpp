// 思路： 贪心， +*  与  ** 的形式中， 一定有一个最大值

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = a + b + c;
    ans = max(ans, (a + b) * c);
    ans = max(ans, a * (b + c));
    ans = max(ans, a * b * c);
    cout << ans << endl;
    return 0;
}