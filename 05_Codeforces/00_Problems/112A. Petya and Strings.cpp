/*
    change -> 大小变小写
    然后通过string 直接比较（string是按照字典序比较的
*/
#include <iostream>

using namespace std;

string str1, str2;

void change(string& str)
{
    for (int i = 0; i < str.size(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main()
{
    cin >> str1 >> str2;
    change(str1), change(str2);

    if (str1 == str2) {
        cout << 0 << endl;
    }
    else if (str1 > str2) {
        cout << 1 << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}