#include <iostream>

using namespace std;

string str;

int main()
{
    cin >> str;
    if ('a' <= str[0] && str[0] <= 'z') {
        str[0] -= 32;
    }
    cout << str << endl;
    return 0;
}