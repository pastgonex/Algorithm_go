#include <iostream>

using namespace std;

char str[100];

int main(void)
{
    // scanf("%[^\n]s", str); //只要不是空格就继续读入
    // puts(str);
    scanf("%[a-z]s", str);
    puts(str);
    return 0;
}
