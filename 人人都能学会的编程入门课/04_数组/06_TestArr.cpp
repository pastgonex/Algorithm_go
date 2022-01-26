#include <iostream>

using namespace std;

int main(void)
{
    int arr[100];
    for (int i = 0; i < 100; i++)
        arr[i] = i + 100;
    printf("%d\n", *(arr + 99));
}
