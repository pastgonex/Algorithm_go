#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int res = 1;
    char last = '\0';
    while (n--) {
        string str;
        cin >> str;
        if (str[0] == last) {
            res++;
        }
        last = str[1];
    }
    cout << res << endl;
    return 0;
}