#include <iostream>

using namespace std;

int func(int x)
{
    return x * 2;
}

int main(void)
{
    int arr[200];
    int n = 100;
    for (int i = 0; i < n; i++)
        arr[i] = i * 2;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", func(i));
    }
    puts("");
    return 0;
}
