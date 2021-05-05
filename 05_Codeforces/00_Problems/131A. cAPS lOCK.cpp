#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int i, l = 0;
    string s;
    cin >> s;
    for (i = 1; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {     
            l++;
        }
    }
    if (l == s.size() - 1) {
        for (i = 0; i < s.size(); i++) {
            if (s[i] >= 65 && s[i] <= 90)
                s[i] = 97 + s[i] - 65;  // da -> xiao 
            else if (s[i] >= 97 && s[i] <= 122)
                s[i] = 65 + s[i] - 97;  // xiao -> da
        }
    }
    cout << s;
    return 0;
}