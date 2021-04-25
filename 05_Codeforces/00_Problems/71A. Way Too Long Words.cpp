/*
    思路： 字符数量小于10不用考虑， 只需要考虑 >10 
*/

#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    while (n--) {
        string a;
        cin >> a;
        int len = a.size();
        if (len > 10) {
            cout << a[0] << len - 2 << a[len - 1] << endl;
        }
        else {
            cout << a << endl;
        }
    }
    return 0;
}