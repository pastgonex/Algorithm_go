#include <iostream>

using namespace std;

int year, month, day;
int x;

bool isLeap()
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int calcMonth()
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 2:
    {
        if (isLeap())
            return 29;
        else
            return 28;
    }
    default:
        return 30;
    }
}

void calc(int x)
{
    int surplus = calcMonth() - day;
    if (surplus >= x)
    {
        printf("%d %d %d", year, month, day + x);
        return;
    }
    else
    {
        x -= surplus;
        day = 0;
        month++;
        if (month > 12)
        {
            year++;
            month = 1;
        }
        calc(x);
    }
    return;
}

int main(void)
{
    printf("Please enter the start date!\n");
    scanf("%d%d%d", &year, &month, &day);
    printf("Please enter the number of days!\n");
    scanf("%d", &x);
    calc(x);
    return 0;
}
