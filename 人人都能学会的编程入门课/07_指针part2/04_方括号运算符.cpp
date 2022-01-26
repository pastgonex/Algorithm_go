#include <iostream>

using namespace std;

int main(void)
{
    int arr[10];
    int *p = arr;
    for (int i = 0; i < 10; i++)
        arr[i] = i;
    printf("%d\n", p[9]);
    return 0;
}
