/*
 * Project: Week3
 * File Created:Wednesday, January 20th 2021, 2:03:16 pm
 * Author: Bug-Free
 * Problem: AcWing 1341. 十三号星期五
 */
#include <iostream>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int weekday[7];

int n;

int main() {
    cin >> n;

    int year = 1900, days = 0;
    // 每一年
    while (n--) {
        for (int i = 1; i <= 12; i++) {  //每个月
            weekday[(days + 12) % 7]++;
            days += month[i];
            if (i == 2) {
                if (year % 4 == 0 && year % 100 || year % 400 == 0) {
                    days++;
                }
            }
        }
        year++;
    }
    for (int i = 5, j = 0; j < 7; i++, j++) {
        cout << weekday[i % 7] << " ";
    }
    return 0;
}
