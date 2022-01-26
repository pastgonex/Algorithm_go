// strlen strcat strcpy
#include <iostream>

using namespace std;

char str1[1000], str2[1000];

int main(void)
{
    scanf("%s%s", str1, str2);
    printf("str1 = %s\tstr2 = %s\n", str1, str2);
    printf("str1的长度: %d\n", sprintf(str1, "%s", str1)); //strlen(str1));
    sprintf(str1, "%s", str2);                             //strcpy(str1,str2)
    printf("str1 = %s\tstr2 = %s\n", str1, str2);
    sprintf(str1, "%s%s", str1, str2); //strcat(str1,str2)
    printf("str1 = %s\tstr2 = %s\n", str1, str2);
    return 0;
}
