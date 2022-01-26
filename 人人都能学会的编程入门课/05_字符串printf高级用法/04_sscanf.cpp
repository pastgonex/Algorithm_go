#include <iostream>

using namespace std;

int main(void)
{
    char str[20] = "123.45";
    double num;
    sscanf(str, "%lf", &num);
    printf("%.2lf\n", num);
    return 0;
}
