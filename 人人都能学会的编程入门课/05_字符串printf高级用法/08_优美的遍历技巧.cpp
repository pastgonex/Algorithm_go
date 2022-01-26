#include <iostream>

using namespace std;

char str[1000];

int main(void)
{
    scanf("%s", str);
    for (int i = 0; str[i]; i++)
        printf("%c\n", str[i]);
    return 0;
}
