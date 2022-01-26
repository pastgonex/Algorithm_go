#include <iostream>

using namespace std;

int main(void)
{
    int n = 1;
    for (int i = 1; i <= 100; i++)
    {
        printf("%2d ", n);
        if (i % 10 == 0)
            printf("\n");
        n = (n * 3) % 101;
    }
    return 0;
}
