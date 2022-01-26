#include <cstdio>
#include <cstdlib>
#include <ctime>
#include<iostream>

using namespace std;
int main()
{
    printf("%d\n", rand() % 1000);
    srand(time(0)); // 设置了随机种子, 如果在srand函数内设置一个固定值, 那么每次运行的结果也是一样的
    printf("%d\n", rand() % 1000);
    return 0;
}
