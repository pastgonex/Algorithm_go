// 求二进制中 1 的个数
#include <iostream>

using namespace std;

int n;
int cnt;

int main(void)
{

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int t = i;
        while (t)
        {

            if (t & 1)
                cnt++;
            t >>= 1;
        }
        printf("%d ", cnt);
        cnt = 0;
    }
    return 0;
}
