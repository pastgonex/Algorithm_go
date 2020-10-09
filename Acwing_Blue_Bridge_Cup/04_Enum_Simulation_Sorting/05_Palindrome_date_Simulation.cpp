#include <cstdio>
#include <iostream>

using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int date) {
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;

    if (!month || month > 13 || !day) return false;

    if (month != 2 && day > months[month]) return false;
    if (month == 2) {
        bool leap = year % 4 == 0 && year % 100 || year % 400 == 0;
        if (day > 28 + leap) return false;
    }
    return true;
}

int main() {
    int date1, date2;
    cin >> date1 >> date2;
    int res = 0;
    for (int i = 1000; i < 10000; i++) {
        int x = i, r = i;
        //从1000开始 翻转  10000001  每次乘10+x%10, x/=10 --> 四次
        //可以手动模拟一下  1234--> 12344321
        for (int j = 0; j < 4; j++) r = r * 10 + x % 10, x /= 10;
        //如果日期在范围之间, 并且是满足要求的, 那么答案++
        if (r >= date1 && r <= date2 && check(r)) res++;
    }
    printf("%d\n", res);
    return 0;
}
