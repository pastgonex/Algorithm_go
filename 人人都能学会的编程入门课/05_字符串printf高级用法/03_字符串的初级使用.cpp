#include <iostream>

using namespace std;

char str[12];

int main(void)
{
    scanf("%[^\n]s", str); // 只要不是 \n就继续读入(包括空格)
    printf("%s", str);
    return 0;
}
