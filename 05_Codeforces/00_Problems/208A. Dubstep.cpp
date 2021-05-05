#include <iostream>

using namespace std;

string str;

int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (i + 2 < str.size() && str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B') {
            cout << " ";
            i += 2;
            continue;
        }
        cout << str[i];  // 根据我们这个算法， 需要枚举每一位
    }
    cout << endl;
    return 0;
}