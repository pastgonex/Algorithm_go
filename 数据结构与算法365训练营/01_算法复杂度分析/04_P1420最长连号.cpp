#include <climits>
#include <cstdio>

const int N = 1e4 + 10;

int n;
int st[N];
int res = INT_MIN;

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &st[i]);
    for (int i = 0; i < n; i++)
    {
        int temp = 1;
        int j = i;
        while (j + 1 < n && st[j + 1] - st[j] == 1)
        {
            temp++, j++;
        }
        if (temp > res)
            res = temp;
    }
    printf("%d\n", res);
}
