#include <iostream>

using namespace std;

int main(void)
{
    int sum = 0;
    for (int i = 1; i < 1000; i++)
        sum += i * (i % 3 == 0 || i % 5 == 0);
    printf("%d\n", sum);
    return 0;
}
