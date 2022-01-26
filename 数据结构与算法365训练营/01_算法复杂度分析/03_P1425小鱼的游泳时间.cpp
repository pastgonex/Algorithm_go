#include <cstdio>
#include <iostream>

using namespace std;

int a, b, c, d;

int main(void)
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int hour = c - a;   //                            6:20
    int minute = d - b; // 3:40 6:20   12:50 19:10 7: -40  6:
    if (minute < 0)
    {
        hour--;
        minute = 60 + minute;
    }
    printf("%d %d\n", hour, minute);
    return 0;
}
