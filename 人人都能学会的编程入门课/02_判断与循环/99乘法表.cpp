#include <iostream>

using namespace std;

int main(void)
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            printf("%d*%d=%d", i, j, i * j);
            if (j < i)
                printf("\t");
        }
        puts("");
    }
    return 0;
}
