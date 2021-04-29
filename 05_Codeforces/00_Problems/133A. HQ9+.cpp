#include <iostream>

using namespace std;

string str;

int main()
{
    cin >> str;
    int flag = false;
    for (int i = 0; i < str.size(); i++) {
        auto t = str[i];
        if (t == 'H' || t == 'Q' || t == '9') {
            flag = true;
            break;
        }
    }
    if (flag) {
        puts("YES");
    }
    else {
        puts("NO");
    }

    return 0;
}