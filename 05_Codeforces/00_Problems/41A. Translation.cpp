#include <algorithm>
#include <iostream>

using namespace std;

string str1, str2;

int main()
{
    cin >> str1 >> str2;
    reverse(str2.begin(), str2.end());
    if (str1 == str2) {
        puts("YES");
    }
    else {
        puts("NO");
    }
    return 0;
}