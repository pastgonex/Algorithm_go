#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(void)
{
    int n = 100;
    srand(time(NULL));
    for (int i = 1; i <= 100; i++)
    {
        printf("%d ", rand() % 100 + 1);

        if (i % 10 == 0)
            puts("");
    }
    return 0;
}
