#include <bitset>
#include <iostream>

using namespace std;

string str1, str2;
string res;

int main()
{
    cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] ^ str2[i]) {
            res += '1';
        }
        else {
            res += '0';
        }
    }
    cout << res << endl;
    return 0;
}