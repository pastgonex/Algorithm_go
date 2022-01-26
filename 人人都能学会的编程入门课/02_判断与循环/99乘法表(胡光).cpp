#include <iostream>

using namespace std;

int main(void)
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            j == 1 || printf("\t");
            printf("%d*%d=%d", j, i, j * i);
        }
        puts("");
    }
    return 0;
}
