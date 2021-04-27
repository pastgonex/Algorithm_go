#include <iostream>

using namespace std;

string str;

int main()
{
    cin >> str;
    int cnt_upper, cnt_lower;
    cnt_upper = cnt_lower = 0;
    for (int i = 0; i < str.size(); i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            cnt_lower++;
        }
        else {
            cnt_upper++;
        }
    }

    if (cnt_upper > cnt_lower) {
        for (int i = 0; i < str.size(); i++) {
            if ('a' <= str[i] && str[i] <= 'z') {
                str[i] -= 32;
            }
        }
    }
    else {
        for (int i = 0; i < str.size(); i++) {
            if ('A' <= str[i] && str[i] <= 'Z') {
                str[i] += 32;
            }
        }
    }
    cout << str << endl;
    return 0;
}