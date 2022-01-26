#include <iostream>

using namespace std;

int main(void)
{
    // 方法1
    // for (int i = 1; i <= 100; i += 2)
    //     printf("%d ", i);
    //方法2
    // int i = 1;
    // while (i <= 100)
    // {
    //     printf("%d ", i);
    //     i += 2;
    // }
    //方法3
    // for (int i = 1; i <= 100; i++)
    //     if (i % 2 == 1)
    //         printf("%d ", i);
    //方法4
    // int i = 1;
    // while (i <= 100)
    // {
    //     if (i % 2 == 1)
    //         printf("%d ", i);
    //     i++;
    // }
    // 方法5
    for (int i = 1; i <= 100; i++)
        if (i & 1)
            printf("%d ", i);
    return 0;
}
