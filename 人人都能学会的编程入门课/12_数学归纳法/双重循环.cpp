#include <iostream>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            printf("%d %d\n", i, j);

    return 0;
}
