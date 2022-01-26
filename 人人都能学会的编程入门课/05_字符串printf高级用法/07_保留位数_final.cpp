#include <iostream>

using namespace std;

char str[1000]; //把 double 作为字符串输入
int k;          //保留的位数
double num;

int main(void)
{
    scanf("%lf%d", &num, &k);
    sprintf(str, "%%.%dlf\n", k);
    printf(str, num); //  "%%.2lf\n",num
    return 0;
}
