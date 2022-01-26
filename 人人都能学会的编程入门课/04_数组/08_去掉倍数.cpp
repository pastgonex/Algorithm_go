#include <iostream>

using namespace std;

const int N = 15;

int n, m;
int num[N];

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]); // n个数字就读入了
    int st = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % num[j] == 0)
            {
                st = 0;
                break;
            }
        }
        if (st)
            printf("%d ", i);
        st = 1;
    }
    return 0;
}
