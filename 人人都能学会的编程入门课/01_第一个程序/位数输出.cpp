#include <iostream>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    printf(" has %d digits\n", printf("%d", n)); //有多余输出
    char output[50];
    printf("%d\n", sprintf(output, "%d", n));
    printf("%s", output);
    return 0;
}
