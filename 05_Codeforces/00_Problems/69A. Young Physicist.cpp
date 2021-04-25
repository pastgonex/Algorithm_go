// 向量和 等价于    x的和+y的和+z的和
#include <iostream>

using namespace std;

int n;
int x, y, z;
int main()
{
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        x += a, y += b, z += c;
    }
    if (x == 0 && x == y && y == z) {
        puts("YES");
    }
    else {
        puts("NO");
    }
    return 0;
}