#include <iostream>

using namespace std;

int n;
string str;
bool st[30];

int main()
{
    cin >> n >> str;
    if (n < 26) {
        puts("NO");
    }
    else {
        for (int i = 0; i < str.size(); i++) {
            if ('A' <= str[i] && str[i] <= 'Z') {
                str[i] += 32;
            }
            if ('a' <= str[i] && str[i] <= 'z') {
                st[str[i] - 'a'] = true;
            }
        }

        bool flag = false;
        for (int i = 0; i < 26; i++) {
            if (!st[i]) {
                puts("NO");
                flag = true;
                break;
            }
        }
        if (!flag) {
            puts("YES");
        }
    }
    return 0;
}