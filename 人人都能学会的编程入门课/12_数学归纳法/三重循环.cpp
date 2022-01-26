#include <iostream>

using namespace std;

int main(void)
{
    int count = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int z = 1; z <= n; z++)
                printf("%d %d %d\n", i, j, z);
    return 0;
}
