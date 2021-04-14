#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int main()
{
    int n;
    scanf("%d", &n);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (i & 1)
            res ^= x;  // 只需要考虑奇数级 台阶上的石子即可
    }

    if (res)
        puts("Yes");
    else
        puts("No");

    return 0;
}