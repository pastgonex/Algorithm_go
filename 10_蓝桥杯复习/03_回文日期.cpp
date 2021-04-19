#include <iostream>

using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int date)
{
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;

    if (!day || !month || month > 12) {
        return false;
    }

    if (month != 2 && day > months[month]) {
        return false;
    }

    if (month == 2) {
        bool leap = year % 4 == 0 && year % 100 || year % 400 == 0;
        if (day > 28 + leap) {
            return false;
        }
    }
    return true;
}

int main()
{
    int date1, date2;
    cin >> date1 >> date2;

    int res = 0;
    for (int i = 1000; i < 10000; i++) {
        int x = i, r = i;  //1000
        for (int j = 0; j < 4; j++) {  // 做四次 
            r = r * 10 + x % 10, x /= 10;
        }

        if (r >= date1 && r <= date2 && check(r)) {
            res++;
        }
    }

    cout << res << endl;

    return 0;
}