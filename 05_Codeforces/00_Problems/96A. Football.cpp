#include <iostream>

using namespace std;

string str;

int main()
{
    cin >> str;
    bool flag = false;
    for (int i = 0; i < str.size(); i++) {
        int res = 1;
        int j = i;
        while (str[j] == str[j + 1]) {
            res++;
            j++;
        }
        if (res >= 7) {
            flag = true;
            break;
        }
        i = j;
    }
    if (flag) {
        puts("YES");
    }
    else {
        puts("NO");
    }
    return 0;
}